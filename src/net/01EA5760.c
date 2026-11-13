/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; u8 f4; s32 f8; s32 fC; u8 f10; s16 f12; s32 f14; s32 f18; } Type1;
extern void (*D_00167F64)(Type1 *);
extern s32 D_00167F68;
void func_01EA5760(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Type1 ev;
    if (D_00167F64 != NULL) {
        ev.f0 = arg0;
        ev.f4 = arg1;
        ev.f8 = arg2;
        ev.fC = arg3;
        ev.f10 = arg4;
        ev.f12 = arg5;
        ev.f14 = arg6;
        ev.f18 = D_00167F68;
        D_00167F64(&ev);
    }
}
