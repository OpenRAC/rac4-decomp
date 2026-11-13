#include "common.h"

extern void *func_L00_005EAC30(void *);
extern void func_L00_005EB528(s32, s32, u32, s32);
extern s32 func_L00_0066D2C8(s32, s32, void *, s32);

void func_L01_005A0DC0(s32 arg0, s32 arg1) {
    u8 *v = func_L00_005EAC30((void *)arg0);
    s32 t;

    if (v != NULL) {
        func_L00_005EB528(arg0, 3, 0x80F08000, 0);
        func_L00_0066D2C8(2, 4, (void *)arg0, 0x201C);
        t = *(s16 *)(v + 0x26);
        if (t < arg1) {
            t = arg1;
        }
        *(s16 *)(v + 0x26) = t;
    }
}
