#pragma once
#include <Windows.h>

namespace Helper {
	class BufferWriter
	{
	public:
		BufferWriter(unsigned int max_length)
		{
			max_length_ = max_length;
			position_ = 0;
			buffer_ = new BYTE[max_length];
		}

		~BufferWriter()
		{
			max_length_ = 0;
			position_ = 0;
			//delete[] buffer_;
			buffer_ = nullptr;
		}

		BYTE *GetBuffer()
		{
			return buffer_;
		}

		unsigned int GetMaxLength()
		{
			return max_length_;
		}

		unsigned int GetPosition() {
			return position_;
		}

		void Write1(unsigned char byte)
		{
			buffer_[position_++] = byte;
		}

		void Write2(unsigned short val)
		{
			BYTE byte1 = val & 0xFF;
			BYTE byte2 = val >> 8;
			Write1(byte1);
			Write1(byte2);
		}

		void Write4(unsigned int val)
		{
			BYTE byte1 = val & 0xFF;
			BYTE byte2 = (val >> 8) & 0xFF;
			BYTE byte3 = (val >> 16) & 0xFF;
			BYTE byte4 = val >> 24;
			Write1(byte1);
			Write1(byte2);
			Write1(byte3);
			Write1(byte4);
		}

		void Write8(unsigned long long val)
		{
			BYTE byte1 = val & 0xFF;
			BYTE byte2 = (val >> 8) & 0xFF;
			BYTE byte3 = (val >> 16) & 0xFF;
			BYTE byte4 = (val >> 24) & 0xFF;
			BYTE byte5 = (val >> 32) & 0xFF;
			BYTE byte6 = (val >> 40) & 0xFF;
			BYTE byte7 = (val >> 48) & 0xFF;
			BYTE byte8 = val >> 56;
			Write1(byte1);
			Write1(byte2);
			Write1(byte3);
			Write1(byte4);
			Write1(byte5);
			Write1(byte6);
			Write1(byte7);
			Write1(byte8);
		}

		void WriteBuffer(BYTE *buffer, unsigned short length)
		{
			Write2(length);
			for (int i = 0; i < length; i++)
			{
				Write1(buffer[i]);
			}
		}

	private:
		unsigned int position_;
		unsigned int max_length_;
		BYTE *buffer_;
	};

}