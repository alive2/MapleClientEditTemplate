#pragma once
#include "Windows.h"

struct MaplePacket
{
	DWORD Unknown1;
	LPVOID Data;
	DWORD Size;
	DWORD Unknown2;
};

struct SendStruct
{
	DWORD ReturnAddy;
	MaplePacket* Data;
};

//typedef DWORD(__stdcall *SendMaplePacket)(MaplePacket *Buffer);

struct COutPacket {
	int Loopback;
	union {
		PUCHAR Data;
		PVOID Unk;
		PUSHORT Header;
	};
	ULONG Size;
	UINT Offset;
	int EncryptedByShanda;
};