#include "common.h"

typedef struct {
    char pad[0x7C];
    f32 f7C;
    char tail[0x38];
} Type1;
typedef struct {
    char pad[0x26E4];
    s32 h;
} Type2;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Type3;
extern Type1 D_00308108[];
extern s32 D_00221650;
extern s32 D_0021EDD4;
extern void func_00497AE0(s32, s32, s32, f32, f32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004A86E0(void);
extern s32 func_00505B20(void);
extern Type2 *func_00510BE8(s32 arg0);
extern s32 func_00547D58(s32 arg0, s32 arg1);
extern s32 func_00548078(s32 arg0, s32 arg1);
extern f32 func_00548280(s32 arg0, s32 arg1);
extern Type3 *func_00548D68(s32 arg0, s32 arg1);

void func_004A8F68(void)
{
    s32 index = func_00505B20();
    Type2 *obj = func_00510BE8(index);
    Type1 *p = &D_00308108[index];
    s32 id = func_004A86E0();
    f32 v;
    s32 a;
    s32 b;

    if (D_0021EDD4 == 1) {
        a = func_00547D58(obj->h, id);
        b = func_00548078(obj->h, id);
        v = (f32)b / (f32)func_00548D68(id, a)->c;
    } else {
        v = func_00548280(obj->h, id);
    }
    if (id == 0) {
        v = 0.0f;
    }
    if (v != p->f7C) {
        s32 h;
        p->f7C = v;
        h = func_004A1A60(&D_00221650, 0x2D);
        func_00497AE0(h, func_004A1A60(&D_00221650, 0x2E), 0, v, 0.0f);
    }
}
