#include "d3hook.h"
#include "includes.h"

#include "pch.h"
#include "memedit.h"
#include "Offsets.h"
#include "SendHook.h"
#include "BufferWriter.h"

#ifdef _WIN64
#define GWL_WNDPROC GWLP_WNDPROC
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace D3 {
	EndScene oEndScene = NULL;
	WNDPROC oWndProc;
	static HWND window = NULL;

	void InitImGui(LPDIRECT3DDEVICE9 pDevice)
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
		io.IniFilename = IMGUI_INI_FILENAME;
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX9_Init(pDevice);
	}

	bool init = false;
	long __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice)
	{
		if (!init)
		{
			InitImGui(pDevice);
			init = true;
		}

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("My Character");

		int cid = ReadValue<int>(0x00BF3CC0);
		ImGui::Text("ID: %d", cid);

		if (ImGui::Button("Send Custom Packet"))
		{
			Helper::BufferWriter writer(3);
			writer.Write2(0x999);
			writer.Write1(0x11);
			MapleHooks::SendPacket(writer);

			OutputDebugStringA("Sent Custom Packet");
		}

		ImGui::End();

		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		return oEndScene(pDevice);
	}

	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
	}

	BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
	{
		DWORD wndProcId;
		GetWindowThreadProcessId(handle, &wndProcId);

		if (GetCurrentProcessId() != wndProcId)
			return TRUE; // skip to next window

		window = handle;
		return FALSE; // window found abort search
	}

	HWND GetProcessWindow()
	{
		window = NULL;
		EnumWindows(EnumWindowsCallback, NULL);
		return window;
	}

	DWORD WINAPI Thread(LPVOID lpReserved)
	{
		bool attached = false;
		do
		{
			if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success)
			{
				kiero::bind(42, (void**)& oEndScene, hkEndScene);
				do
					window = GetProcessWindow();
				while (window == NULL);
				oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
				attached = true;
			}
		} while (!attached);
		return TRUE;
	}
}