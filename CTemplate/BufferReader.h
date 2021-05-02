#pragma once

#include <Windows.h>
#include <string>
#include <bitset>

namespace Helper {
	class BufferReader {
	public:
		BufferReader(BYTE* packet, int length) {
			offset_ = 0;
			length_ = length;
			packet_ = packet;
		}

		int Available() {
			return length_ - offset_;
		}

		BYTE ReadByte() {
			return (BYTE)packet_[offset_++];
		}

		unsigned short ReadShort() {
			unsigned short byte1 = ReadByte();
			unsigned short byte2 = ReadByte() << 8;
			return byte1 | byte2;
		}

		unsigned int ReadInt() {
			unsigned int byte1 = ReadByte();
			unsigned int byte2 = ReadByte() << 8;
			unsigned int byte3 = ReadByte() << 16;
			unsigned int byte4 = ReadByte() << 24;
			return byte1 | byte2 | byte3 | byte4;
		}

		std::string ReadString() {
			short length = ReadShort();
			std::string str;
			for (int i = 0; i < length; i++) {
				str += ReadByte();
			}
			return str;
		}

	private:
		int offset_;
		int length_;
		BYTE* packet_;
	};
}