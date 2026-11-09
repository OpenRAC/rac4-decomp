/* Not matching yet: BYTES 1/116 (tools/try_func.py func_L00_0053C960 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern char *func_L00_004FACD8(s32 size);
extern s32 func_L00_00516F10();
extern void func_004FAD28(void *p);

/* Allocate the 0x14 record, take the id and publish it on the owner; a failed
   id releases the record again. */
s32 func_L00_0053C960(char *owner)
{
    s32 *p = (s32 *)func_L00_004FACD8(0x14);
    s32 v;

    if (p == 0) {
        return 0;
    }
    v = func_L00_00516F10();
    if (v == 0) {
        func_004FAD28(p);
        return 0;
    }
    p[0] = v;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    *(s32 *)(owner + 0xC) = (s32)p;
    return 1;
}
