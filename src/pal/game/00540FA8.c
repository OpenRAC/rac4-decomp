#include "common.h"

typedef struct Data {
    s16 coordinate;
    u8 pad[14];
    s32 result;
    s32 value;
} Data;

s32 D_00220E7C = 0;
extern s32 D_00220C30;
extern s32 func_00512228(s32, s32);
extern void *func_0053DCD0(s32, s32, s32, s32);
extern void func_0053DE58(void *, void *, s32);

s32 func_00540FA8(s16 a0, s16 a1, void **a2, s32 *a3)
{
    s32 result;
    void *context;
    Data data;
    s32 value;

    result = func_00512228(6, -1);
    context = func_0053DCD0(D_00220E7C, 0, 0, 0xFA);
    value = D_00220C30;
    if (a3 != 0) {
        value = *a3;
    }
    data.result = result;
    func_0053DE58(context, &data.result, 4);
    data.coordinate = a0;
    func_0053DE58(context, &data.coordinate, 2);
    data.coordinate = a1;
    func_0053DE58(context, &data.coordinate, 2);
    data.value = value;
    func_0053DE58(context, &data.value, 4);
    if (a2 != 0) {
        *a2 = context;
    }
    return result;
}
