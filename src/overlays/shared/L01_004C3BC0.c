#include "common.h"

typedef struct Type2 {
    char _p0[0x351];
    u8 f351;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

extern f32 func_L00_005DD730(Type1 *arg0);
extern void func_L00_005DE048(void *, s32, void *);
extern void func_L01_00592CD0(void *arg0, Type1 *arg1, s32 arg2, f32 arg3);
extern void func_L00_005A7230(void *arg0, s32 arg1, Type1 *arg2, void *arg3, f32 arg4);

s32 func_L01_004C3BC0(Type1 *arg0, s32 arg1) {
    Type2 *p = arg0->fAC;
    s32 buf[12];
    s32 vec[4];
    f32 t;

    if (arg1 == 1) {
        t = func_L00_005DD730(arg0);
        if (t >= 14.0f && t <= 16.0f) {
            func_L00_005DE048(arg0, 0, vec);
            func_L01_00592CD0(buf, arg0, 0x801, p->f351);
            func_L00_005A7230(vec, 0, arg0, buf, 0.5f);
        }
    }
    return 1;
}
