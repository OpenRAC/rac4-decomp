#include "common.h"

f32 func_L01_004CA990(void *p) {
    u32 ptr=*(u32*)((u8*)p+0xAC);return (f32)*(s32*)(ptr+4)/(f32)*(s32*)ptr;
}
