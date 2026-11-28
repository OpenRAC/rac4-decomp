#include "common.h"

typedef struct __attribute__((packed, aligned(4))) Block12 {
    s64 head;
    s32 tail;
} Block12;

extern s32 func_00540FA8(s16, s16, void **, s32 *);
extern void func_0053DE58(void *, void *, s32);

/* Opens a 0x50 packet and appends two 12-byte blocks plus two words. */
s32 func_L41_00417EE8(s32 *owner, void *first, void *second, s16 kind, s32 word0, s32 word1)
{
    Block12 copy;
    void *packet;
    s32 result;
    s32 a;
    s32 b;

    copy = *(Block12 *)second;
    packet = NULL;
    result = func_00540FA8(kind, 0x50, &packet, owner);
    if (packet != NULL) {
        func_0053DE58(packet, first, 0xC);
        func_0053DE58(packet, &copy, 0xC);
        a = word0;
        func_0053DE58(packet, &a, 4);
        b = word1;
        func_0053DE58(packet, &b, 4);
    }
    return result;
}
