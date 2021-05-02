#include "RecvHook.h"
#include "Offsets.h"
#include "MaplePacket.h"
#include "BufferReader.h"
#include <string>

// Should be moved somewhere else
#define JMP(frm, to) (int)(((int)to - (int)frm) - 5);

namespace MapleHooks {
	namespace {
		MaplePacket* DataStructRecv;
	}

	std::string ToStringArray(LPVOID PacketData, INT Length)
	{
		BYTE* Bytes = (BYTE*)PacketData;
		std::string Packet = "";
		char Buf[20];

		for (int i = 0; i < Length; i++)
		{
			sprintf_s(Buf, "%02X", Bytes[i]);
			Packet += Buf;
			if (i != (Length - 1))
				Packet += " ";
		}
		printf("\n");
		return Packet;
	}

	void HandleRecvPacket() {
		// OutputDebugStringA(ToStringArray(DataStructRecv->Data, DataStructRecv->Size).c_str());

		BYTE* bytes = (BYTE*)(DataStructRecv->Data);
		Helper::BufferReader reader = Helper::BufferReader(bytes, (int)DataStructRecv->Size);
		short opcode = reader.ReadShort();

		if (opcode == 0x999) {
			char data = reader.ReadByte();

			OutputDebugStringA("My Custom Packet");
		}
	}

	void __declspec(naked) __stdcall RecvHook() {
		__asm {
			push eax
			mov eax, ebp
			sub eax, 0ch
			mov dword ptr[DataStructRecv], eax
			pop eax
			pushad
			call[HandleRecvPacket]
			popad
			pop esi
			pop ebx
			leave
			ret 4
		}
	}

	void PacketRecvHook() {
		//Protect
		DWORD oldprotection;
		VirtualProtect((LPVOID)Offsets::CInPacketDecryptDataRet, 5, PAGE_EXECUTE_READWRITE, &oldprotection);

		//Hook
		*(BYTE*)Offsets::CInPacketDecryptDataRet = 0xE9;
		*(DWORD*)(Offsets::CInPacketDecryptDataRet + 1) = JMP(Offsets::CInPacketDecryptDataRet, RecvHook);
	}
}