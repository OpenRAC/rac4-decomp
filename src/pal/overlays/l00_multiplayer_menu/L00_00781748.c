#include "common.h"

void func_L00_00781748(void) {
    u32 base=*(u32*)0x2234A4;
    u32 sub=*(u32*)(base+0x68);
    *(u8*)(sub+0x60)=0;
    *(u8*)(sub+0x6C)=0;
}
