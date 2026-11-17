/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern char *func_00122160(char *searchee, char *lookfor);
extern void func_01F0C090(const char *, s32);
extern char D_0019E360[];
extern char D_0019E380[];

typedef struct Type1 {
    char b[15];
} __attribute__((packed)) Type1;

/* Copies the 15-byte record at arg0 to a local, ends it at the match offset, and returns 1 if the search string is found. */
s32 func_01F06F10(char *arg0) {
    Type1 buf;
    char *p;
    s32 n;
    s32 ret = 0;

    p = func_00122160(arg0, D_0019E380);
    n = p - arg0;
    if (p != NULL) {
        if (n >= 0xF) {
            func_01F0C090(D_0019E360, 0x14E);
        }
        buf = *(Type1 *)arg0;
        buf.b[n] = 0;
        ret = 1;
    }
    return ret;
}
