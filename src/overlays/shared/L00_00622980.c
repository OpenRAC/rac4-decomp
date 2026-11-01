#include "common.h"

extern u8 D_0030CBC0[];
extern u8 D_004C9E88[];

typedef struct {
    u8 pad0[0xC];
    void (*func)(s32);
} Type1;

void func_L00_00622980(s32 arg0) {
    s32 offset;
    u8 *ptr;
    s32 field4;
    Type1 *entry;
    void (*func_ptr)(s32);

    offset = arg0 * 0x3C;
    ptr = D_0030CBC0 + offset;

    if (*ptr != 0) {
        field4 = *(s32 *)(ptr + 4);
        entry = (Type1 *)(D_004C9E88 + (field4 << 4));
        func_ptr = entry->func;
        if (func_ptr != NULL) {
            func_ptr(arg0);
        }
    }
}
