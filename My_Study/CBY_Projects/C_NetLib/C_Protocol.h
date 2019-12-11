#pragma once
#include <Windows.h>
#define PACKET_HEADER_SIZE 4
#define PACKET_MAX_DATA_SIZE 2044
#define PACKET_MAX_SIZE (PACKET_MAX_DATA_SIZE+PACKET_HEADER_SIZE)

#pragma pack(push, 1)
typedef struct
{
	WORD len;
	WORD type;
}PACKET_HEADER;

typedef struct
{
	PACKET_HEADER ph;
	char data[PACKET_MAX_DATA_SIZE];
}USERPAKET;
#pragma pack(pop)

#define PACKET_CHAT_MSG 2000