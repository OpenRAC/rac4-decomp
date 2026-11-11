/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x34];
    s32 f34;
    char _p38[0x3E4];
    void *f41C;
    void *f420;
};

s32 func_01EE1690(s32);
s32 func_01EE1A10(s32);
extern s32 D_0016A930;
extern void (*D_0016A938)(void *);

s32 func_01EDF6C0(Type1 *arg0) {
    s32 temp_v0;

    if (arg0 != NULL) {
        temp_v0 = arg0->f34;
        if (temp_v0 != 0) {
            func_01EE1690(temp_v0);
            func_01EE1A10(arg0->f34);
        }
        D_0016A938(arg0->f420);
        D_0016A938(arg0->f41C);
        D_0016A938(arg0);
        D_0016A930 -= 1;
    }
    return 0;
}
