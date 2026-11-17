#include "common.h"

s32 D_00220DDC = 0;
extern s32 D_00220B98;
extern u32 func_00511150(s32 index, s32 id);
extern void *func_0053C920(int *arg0, int arg1, int arg2, int arg3);
extern void func_0053CAA8(u8 *arg0, s32 arg1, s32 arg2);

/* Creates an object, sends it its id, two halfwords and a value, and returns the id. */
s32 func_0053FBA8(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3) {
    s32 id;
    s32 id_out;
    u8 *obj;
    s16 pos[8];
    s32 val;
    s32 val_out;

    id = func_00511150(6, -1);
    obj = func_0053C920((int *)D_00220DDC, 0, 0, 0xFA);
    val = D_00220B98;
    if (arg3 != 0) {
        val = *arg3;
    }
    id_out = id;
    func_0053CAA8(obj, (s32)&id_out, 4);
    pos[0] = arg0;
    func_0053CAA8(obj, (s32)pos, 2);
    pos[0] = arg1;
    func_0053CAA8(obj, (s32)pos, 2);
    val_out = val;
    func_0053CAA8(obj, (s32)&val_out, 4);
    if (arg2 != 0) {
        *arg2 = (s32)obj;
    }
    return id;
}
