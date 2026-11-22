#include "common.h"
extern u8 D_00222B28;
extern u8 D_003AB6A0[];
extern void func_004512D0(u8 *, void *, s32, u8 *, s32);
typedef struct { s32 a; s32 b; u8 d; s32 c; u8 pad[0x30]; } E;
void func_L01_004DD880(E *p, s32 *x, s32 *y) {
    s32 i;
    func_004512D0(&D_00222B28, p, 2, D_003AB6A0, 1);
    for (i = 1; i >= 0; i--) {
        p->d = 0;
        p->c = 0;
        p->a = *x++;
        p->b = *y++;
        p++;
    }
}
