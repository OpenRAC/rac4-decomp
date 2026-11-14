#include "common.h"

extern void func_L00_006EC318(void *, s32 *, s32);
extern s32 func_L01_006B4FC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// Open a stream for the object and write the two words at 0x80/0x84 of its linked block.
void func_L41_00443AE0(s32 object) {
    s32 buf[2];
    char *linked;
    s32 stream = func_L01_006B4FC0(object, 0, 0, 0xFA);
    linked = *(char **)((char *)object + 0xAC);
    if (stream) {
        buf[0] = *(s32 *)(linked + 0x80);
        func_L00_006EC318((void *)stream, &buf[0], 4);
        buf[1] = *(s32 *)(linked + 0x84);
        func_L00_006EC318((void *)stream, &buf[1], 4);
    }
}
