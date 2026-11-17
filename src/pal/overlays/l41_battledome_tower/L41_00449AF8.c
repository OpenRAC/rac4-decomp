#include "common.h"

extern void func_0046C6B0(void *);

void func_L41_00449AF8(void *arg0) {
    void *object = *(void **)((u8 *)arg0 + 0xAC);
    void *first = *(void **)((u8 *)object + 0x18);
    void *second;
    if (first != 0) {
        func_0046C6B0(first);
    }
    second = *(void **)((u8 *)object + 0x1C);
    *(void **)((u8 *)object + 0x18) = 0;
    if (second != 0) {
        func_0046C6B0(second);
    }
    *(void **)((u8 *)object + 0x1C) = 0;
    *(s32 *)((u8 *)object + 0x84) = 0;
}
