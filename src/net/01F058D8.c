/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC0];
    s32 fC0[1];
    char _pC4[0x18C];
    s32 f250;
    s32 f254;
    s32 f258;
    s32 f25C;
    s32 f260;
};

extern void func_01F0C090(void *, s32);
extern s32 D_0019E200[];

/* Logs each limit that the record at arg0 is past, then returns the entry at index f25C. */
s32 func_01F058D8(Type1 *arg0) {
    if (arg0->f258 == 0) {
        return 0;
    }
    if (arg0->f250 >= 0x65) {
        func_01F0C090(D_0019E200, 0x190);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x191);
    }
    if (arg0->f25C < arg0->f260) {
        func_01F0C090(D_0019E200, 0x192);
    }
    if (arg0->f25C >= arg0->f260 + arg0->f254) {
        func_01F0C090(D_0019E200, 0x193);
    }
    return arg0->fC0[arg0->f25C];
}
