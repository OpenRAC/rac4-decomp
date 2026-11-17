/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern char *func_00122160(char *searchee, char *lookfor);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019B460[];
extern char D_0019B690[];
extern char D_0019B698[];

typedef struct {
    u8 b[15];
} Type15;

/* Copies the 15-byte record at arg1 into a local buffer and runs the callee on it. */
s32 func_01EE8160(s32 arg0, char *arg1) {
    char buf[16];
    char *end;
    s32 len;
    s32 ret;

    ret = 0;
    end = func_00122160(arg1, D_0019B690);
    if (end != 0) {
        len = end - arg1;
        if (len >= 0xF) {
            func_01F0C090(D_0019B460, 0x777);
        }
        *(Type15 *)buf = *(Type15 *)arg1;
        buf[len] = 0;
        ret = func_0011A8A0(buf, D_0019B698) == 0;
    }
    return ret;
}
