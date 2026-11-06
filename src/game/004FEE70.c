#include "common.h"

typedef struct Type1 {
    u8 pad0[0x18];
    s32 *a[6];
    s32 *b[6];
    s32 n[6];
    f32 f60;
} Type1;

extern void func_005024D0(s32 *arg0, s32 *arg1, s32 *arg2);
u8 D_00220AA0[8] = { 2, 3, 2, 1, 1, 1, 0, 0 };

s32 *func_004FEE70(Type1 *arg0, s32 *arg1) {
    s32 idx;
    s32 count;
    s32 *result;

    idx = 0xFFFF;
    count = 0;
    result = NULL;
    func_005024D0(arg1, &idx, &count);
    arg1++;
    idx--;
    if ((u32)idx < 6 && count != 0) {
        arg0->f60 = *(f32 *)arg1;
        arg0->a[idx] = arg1 + 1;
        arg0->b[idx] = arg1 + count + 1;
        arg0->n[idx] = count;
        if (idx == 3) {
            result = arg0->b[3] + D_00220AA0[3];
        } else if (idx == 4) {
            result = arg0->a[4] + count * D_00220AA0[4];
        } else {
            result = arg0->b[idx] + count * D_00220AA0[idx];
        }
    }
    return result;
}
