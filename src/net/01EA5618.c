/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } B8;
typedef struct { char _p0[0x18]; B8 f18; s32 f20; } X;
extern X *D_00167EFC;
s32 func_01EA55E8();
void func_01EA1368(s32 a0, s32 o, s32 a2, s32 a3, s32 a4);
void func_01EA5618(s32 a0, B8 p, s32 a2, s32 a3, s32 a4) {
    D_00167EFC->f18 = p;
    D_00167EFC->f20 = a2;
    func_01EA1368(func_01EA55E8(), 0, 0x100, a3, a4);
}
