/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern char *func_00122160(char *searchee, char *lookfor);
extern void func_01EED528(s32 arg0);
extern void *func_01F07100();
extern s32 func_01F07300();
extern void func_01F0C090(const char *, s32);
extern u8 D_0019B460[];
extern char D_0019B690[];

/* Copies the 15-byte record at arg1 into a local buffer, clears the byte at the match offset and passes the buffer to func_01F07300. */
s32 func_01EE8090(s32 arg0, char *arg1) {
    typedef struct { char b[15]; } Rec;
    Rec buf;
    char *found;
    s32 s2;
    s32 ret;

    ret = 0;
    found = func_00122160(arg1, D_0019B690);
    if (found != 0) {
        s2 = found - arg1;
        if (s2 >= 0xF) {
            func_01F0C090(D_0019B460, 0x74D);
        }
        buf = *(Rec *)arg1;
        buf.b[s2] = 0;
        ret = func_01F07300(func_01F07100(), &buf);
        if (ret == 0) {
            func_01EED528(0x20);
        }
    }
    return ret;
}
