/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Client Client;
typedef struct Packet {
    u32 words[16];
} Packet;

extern Packet *func_0012A020(Client *client);
extern Packet *func_0012A050(Client *client, s32 index);
extern s32 func_00129B58(u32 command, void *packet, s32 size,
                         const void *extra, u32 remoteAddress, s32 extraSize);
extern s32 func_0012A160(u32 unusedHandle, u64 unusedPeriod, u64 unusedElapsed,
                         Packet *packet);
extern s32 func_0012EAA8(u64 delay, s32 (*callback)(u32, u64, u64, Packet *),
                         Packet *packet);

void func_0012A1A0(Packet *request, Client *client)
{
    Packet *packet;

    if (request->words[4] & 4) {
        packet = func_0012A050(client, request->words[4] >> 16);
    } else {
        packet = func_0012A020(client);
    }
    {
        u32 selfAddress = request->words[5];
        u32 clientAddress = request->words[7];

        packet->words[5] = selfAddress;
        packet->words[7] = clientAddress;
    }
    packet->words[8] = 0x8000000C;
    packet->words[9] = request->words[8];
    packet->words[10] = request->words[9];
    packet->words[11] = request->words[10];
    if (func_00129B58(0x80000008, packet, 64,
                      (const void *)request->words[8], request->words[9],
                      (s32)request->words[10]) == 0) {
        func_0012EAA8(2048, func_0012A160, packet);
    }
}
