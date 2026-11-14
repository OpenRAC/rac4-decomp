/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern void *func_00517808(void);
extern s32 func_L00_004FAAF0(void *, s32, s32, void *, s32);
extern void func_L00_0051AC70(s32 a, void *b, void *c);
extern char D_004AD120[];

typedef struct V { u8 pad[0x20]; void (*f20)(void *); } V;
typedef struct O {
    V *f0;
    s64 (*f4)(struct O *, s32, s32, s32, s32, s32);
    u8 pad[0x24];
    u8 f2C[0x14];
    void *f40;
} O;

// Tear down object: run its callbacks and free it, returning 1 on success.
s32 func_L00_005168B0(O *arg0) {
    s32 s1 = *(s32 *)func_00517808();
    s32 r;
    if (arg0 == 0) return 0;
    if (func_L00_004FAAF0(arg0->f2C, -1, 0x12, D_004AD120, 0x7F) > 0) return 1;
    if (arg0->f4 != 0) {
        r = (s32)arg0->f4(arg0, 1, 0, 0, 0, 1);
        if (r <= 0) return r;
    }
    if (arg0->f40 != 0) {
        func_L00_0051AC70(s1, arg0, arg0->f40);
        func_004FAD28(arg0->f40);
    }
    if (arg0->f0 != 0 && arg0->f0->f20 != 0) {
        arg0->f0->f20(arg0);
        func_004FAD28(arg0);
    }
    return 1;
}
