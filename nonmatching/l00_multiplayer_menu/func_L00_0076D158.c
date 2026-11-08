/* Not matching yet: SIZE ours 116 / retail 120 (tools/try_func.py func_L00_0076D158 --diff). Not part of the build. */
#include "common.h"

// Take the next entry off the 0x8 free list and give it a new index.
u8 *func_L00_0076D158(u8 *p) {
    u8 *e = *(u8 **)(p + 0x8);
    u32 index;
    u32 value;

    if (e == 0) {
        return e;
    }
    *(u8 **)(p + 0x8) = *(u8 **)(e + 0xD4);
    *(s32 *)(e + 0xD4) = 0;
    index = *(u32 *)(p + 0xC);
    *(u32 *)(p + 0xC) = index + 1;
    value = (*(u32 *)(e + 0x4) & 0xFFF) | (index << 12);
    *(u32 *)(e + 0x4) = value;
    if (value == 0xFFFFFFFF) {
        index = *(u32 *)(p + 0xC);
        *(u32 *)(p + 0xC) = index + 1;
        *(u32 *)(e + 0x4) = (*(u32 *)(e + 0x4) & 0xFFF) | (index << 12);
    }
    return e;
}
