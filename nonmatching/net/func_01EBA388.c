/* Not matching yet: BYTES 85/152 (tools/try_func.py func_01EBA388 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 f0;
    u8 f1;
    u16 b;
    u16 c;
} __attribute__((packed)) Type1;

extern s32 func_01EBB0E0(s32, s32, s32, s32);

/* Uses the packet's index to find a 0x50-byte entry and releases one of its handles. */
s32 func_01EBA388(u8 *arg0, s32 arg1, Type1 *arg2) {
    Type1 packet = *arg2;
    u8 *e = (u8 *)(((packet.b << 2) + packet.b) << 4) + *(s32 *)(arg0 + 0x184);

    if (*(u16 *)(e + 0x34) == packet.c) {
        if (*(s32 *)(e + 4)) {
            func_01EBB0E0(arg0, *(s32 *)(e + 4), 1, 0xD2F3);
        } else if (*(s32 *)(e + 8)) {
            func_01EBB0E0(arg0, *(s32 *)(e + 8), 1, 0xD2F3);
        }
    }
    return 0;
}
