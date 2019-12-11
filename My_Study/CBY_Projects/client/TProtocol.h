#pragma once
#include <windows.h>
#define PACKET_MAX_MSG_SIZE 2048
#pragma pack(push,1)
typedef struct {
	WORD len;
	WORD type;
}PACKET_HEADER;

typedef struct {
	PACKET_HEADER ph;
	char		  msg[PACKET_MAX_MSG_SIZE];
}UPACKET;

typedef struct {
	int   iID;
	char  name[64];
}CREATEUSER;
#pragma pack(pop)

#define PACKET_HEAD_SIZE 4
#define PACKET_MAX_SIZE (PACKET_HEAD_SIZE+PACKET_MAX_MSG_SIZE)
#define PACKET_CHAT_MSG 1000
#define PACKET_LOGIN_SUCCEEDED 2000
#define PACKET_LOGIN_FAILED    2001

// char buffer[] ="0"
//UPACKET sendPacket;
//sendPacket.ph.len = 0+PACKET_HEAD_SIZE;
//sendPacket.ph.type = PACKET_CHAT_MSG;
//sendPacket.msg = 0;//buffer;
// send(sock, (char*)sendPacket, sendPacket.ph.len,0);