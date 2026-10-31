#include "common.h"

extern void func_004706F0(void *);
typedef int u128 __attribute__((mode(TI)));

/* Copies the header bytes and two 16-byte blocks of arg1 into arg0, then calls func_004706F0; with arg1 NULL it only marks arg0 empty. */
void func_0047B9B8(void *arg0, void *arg1) {
    *(u8 *)((u8 *)arg0 + 0x31) = 1;
    if (arg1 != NULL) {
        *(void **)((u8 *)arg0 + 0xB8) = arg1;
        *(u8 *)((u8 *)arg0 + 0x30) = *(u8 *)((u8 *)arg1 + 0x30);
        *(u16 *)((u8 *)arg0 + 0x32) = *(u16 *)((u8 *)arg1 + 0x32);
        *(u128 *)((u8 *)arg0 + 0x10) = *(u128 *)((u8 *)arg1 + 0x10);
        *(u128 *)((u8 *)arg0 + 0xF0) = *(u128 *)((u8 *)arg1 + 0xF0);
        *(u64 *)((u8 *)arg0 + 0x38) = *(u64 *)((u8 *)arg1 + 0x38);
        func_004706F0(arg0);
    } else {
        *(u8 *)((u8 *)arg0 + 0x30) = 0xFF;
        *(u16 *)((u8 *)arg0 + 0x32) = 0xFF;
    }
}
