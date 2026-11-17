/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Obj;
typedef struct { s32 w[7]; } Buf;
extern s32 func_01EA96A8(Obj *, s32, s32);
extern void *func_0011A518(void *, s32, u32);
extern void func_00126E20(s32);
extern void func_0012A270(Buf *, s32, s32, s32, s32);
s32 func_01EC2F68(s32 a, s32 b, Obj *o) {
    Buf buf;
    if (o == 0) {
        return 2;
    }
    if (func_01EA96A8(o, b, 0x40) != 0) {
        return 100;
    }
    if (o->f4 == 0) {
        return 100;
    }
    func_0011A518(&buf, 0, sizeof(Buf));
    func_00126E20(0);
    func_0012A270(&buf, a, o->f4, b, 0);
    func_00126E20(0);
    return 0;
}
