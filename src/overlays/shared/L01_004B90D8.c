#include "common.h"
extern void func_L01_004B6BA8(void *);
extern void func_L01_005ABD28(void *, f32, f32);
extern void func_00480FB8(void *, s32, void *, s32, s32, s32, f32);
extern void func_00473A88(void *, s32, s32);
extern void func_L01_004B8E10(void);
typedef struct S { u8 pad[0x50]; s32 f50; } S;
typedef struct O { u8 pad[0xAC]; S *p; } O;
void func_L01_004B90D8(O *o, s32 sel, f32 *v) {
    S *s = o->p;
    func_L01_004B6BA8(o);
    switch (sel) {
    case 1:
        s->f50 |= 0xC00;
        func_L01_005ABD28(o, v[0] * 0.016666668f, v[1] * 0.016666668f);
        func_00480FB8(o, 7, func_L01_004B8E10, 0, 0, 0, 4.5f);
        func_00473A88(o, 1, 1);
        break;
    case 0:
        func_L01_005ABD28(o, v[0] * 0.016666668f, v[1] * 0.016666668f);
        func_00480FB8(o, 7, func_L01_004B8E10, 0, 0, 0, 4.5f);
        func_00473A88(o, 1, 1);
        break;
    }
}
