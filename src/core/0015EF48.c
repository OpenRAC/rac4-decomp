#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 D_01F31380[];

void func_0015EF48(void *arg0) {
    u8 byte_val;
    void *ptr;

    byte_val = *(u8 *)((u8 *)arg0 + 1);
    ptr = (void *)((u32)(&D_01F31380[0]) + (byte_val * 0xAD0));
    if (ptr != NULL) {
        func_0011A9EC((u8 *)ptr + 0x18, (u8 *)arg0 + 0x1C);
    }
}
