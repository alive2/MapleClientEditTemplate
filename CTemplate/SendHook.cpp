#include "SendHook.h"
#include "MaplePacket.h"
#include <string>

namespace MapleHooks {
	ULONG clientSocketAddr = 0x00BE7914;
	ULONG COutPacketAddr = 0x0049637B;

	PVOID* ClientSocket = reinterpret_cast<PVOID*>(clientSocketAddr);
	typedef void(__thiscall* PacketSend)(PVOID clientSocket, COutPacket* packet);
	PacketSend Send = reinterpret_cast<PacketSend>(COutPacketAddr);

	bool SendPacket(Helper::BufferWriter writer) {
		COutPacket Packet;
		SecureZeroMemory(&Packet, sizeof(COutPacket));

		Packet.Size = writer.GetPosition();
		Packet.Data = writer.GetBuffer();

		char output[50];
		sprintf_s(output, "size: %d", Packet.Size);
		OutputDebugStringA(output);
		sprintf_s(output, "data: %2x", Packet.Data[0]);
		OutputDebugStringA(output);

		try {
			Send(*ClientSocket, &Packet);
			return true;
		}
		catch (...) {
			return false;
		}
	}
}