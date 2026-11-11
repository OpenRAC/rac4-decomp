/* Not matching yet: BYTES 6/464 (tools/try_func.py func_004A68D8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x14];
    s8 unk18;
    u8 pad19[3];
    f32 unk1C;
    s8 unk20;
    u8 pad21[0xF];
    s32 unk30;
    f32 unk34;
    u8 pad38[0x38];
    s32 unk70;
    u8 pad74[4];
    s32 unk78;
    f32 unk7C;
    s32 unk80;
    u8 pad84[4];
    s32 unk88;
    u8 pad8C[8];
    s32 unk94;
    s32 unk98;
    f32 unk9C;
    u8 padA0[0x14];
    s8 unkB4;
    u8 padB5[3];
} Type308108;

extern s32 func_00496BF0(s32 arg0);
extern s32 func_00498120(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004A9990(void);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00548DA0(s32 arg0, s32 arg1);

extern s32 D_0021EDD4;
extern s32 D_00221650;
extern Type308108 D_00308108[];

void func_004A68D8(void) {
    s32 id;
    Type308108 *p;
    u8 *obj;
    s32 flag;
    s8 flag2;
    s32 i;

    flag = 0;
    id = func_00505B20();
    p = &D_00308108[id];
    obj = func_00510BE8(id);
    p->unk7C = 905.3902f;
    p->unk80 = 4;
    p->unk70 = -1;
    p->unk78 = -1;
    p->unk94 = -1;
    p->unk88 = 0;
    p->unk30 = 0;
    p->unk9C = func_00496BF0(id);
    p->unk1C = 0.0f;
    p->unkB4 = 0;
    p->unk20 = 0;
    if (p->unk9C == p->unk1C || func_00498120(id) != 1) {
        flag = 1;
    }
    p->unk0 = 0;
    p->unk34 = flag;
    flag2 = 0;
    if (D_0021EDD4 != 1 && (func_00548DA0(*(s32 *)(obj + 0x26E4), 10) != 0 ||
            func_00548DA0(*(s32 *)(obj + 0x26E4), 9) != 0)) {
        flag2 = 1;
    }
    p->unk18 = flag2;
    func_004A9990();
    i = 0;
    func_005054F8(func_004A1A60(&D_00221650, 0x34), 0x7581);
    do {
        func_005054F8(func_004A1A60(&D_00221650, i + 0x28), 0x7581);
        i++;
    } while (i < 2);
    i = 0;
    do {
        func_005054F8(func_004A1A60(&D_00221650, i + 0x18), 0x7581);
        i++;
    } while (i < 9);
    D_00308108[id].unk98 = 0x3FF;
}
