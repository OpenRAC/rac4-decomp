/* Not matching yet: BYTES 5/116 (tools/try_func.py func_01EA3348 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(char *p, s32 fill, s32 n);
extern void func_01E9E710(char *p);

/* Initialise the object: clear 0xC0 bytes, seed the control words and reset
   the 0x30 sub-block; a null object reports 0x17. */
s32 func_01EA3348(char *obj)
{
    s32 r = 0x17;

    if (obj != 0) {
        func_0011A518(obj, 0, 0xC0);
        *(s32 *)(obj + 0x2C) = 8;
        *(s32 *)(obj + 0xA8) = 0;
        *(s32 *)(obj + 0xAC) = 0;
        *(s32 *)(obj + 0xB4) = 1;
        *(s32 *)(obj + 0xB0) = 0;
        *(s32 *)(obj + 0xBC) = *(s32 *)(obj + 0xB8) = 0x2000;
        func_01E9E710(obj + 0x30);
        *(s32 *)obj = 1;
        r = 0;
    }
    return r;
}
