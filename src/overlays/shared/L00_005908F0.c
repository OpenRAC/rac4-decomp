#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef struct {
    u8 pad[28];
    u8 *p1C;
} M_3E6CA8;
typedef int s128_003E8C50 __attribute__((mode(TI)));
typedef struct {
    u8 pad[512];
    u8 data[48];
    s128_003E8C50 q;
    u8 pad2[1120 - 576];
} Slot_003E8C50;
typedef struct {
    u8 pad[56];
    u8 a38[4];
    u8 a3C[4];
} Base_003E8C50;
typedef struct {
    u8 pad[28];
    Base_003E8C50 *p;
} Ent_003E8C50;
typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;
extern M_3E6CA8 *D_002220D0;
extern void func_L00_00590790(Obj_003E8C50 *);
extern void func_005BCBF0(Obj_003E8C50 *, void *, s32);
extern void func_L00_005908F0(Obj_003E8C50 *obj);
extern Entry_3E6C58 D_0022CA80[];

/* from rac3-decomp's func_L01_003EAAE8, constants adapted */
void func_L00_005908F0(Obj_003E8C50 *obj) {
    Slot_003E8C50 *s = (Slot_003E8C50 *)(obj->f94 * 1136 + (u8 *)((Slot_003E8C50 *)&D_0022CA80));
    Base_003E8C50 *base = (*(Ent_003E8C50 * *)&D_002220D0)[obj->h84].p;
    if (base->a3C[obj->f94]) {
        base->a3C[obj->f94] = 0;
        obj->q30 = s->q;
        func_005BCBF0(obj, s->data, 48);
    } else {
        s32 *z = obj->f70;
        z[0] = 0;
        z[2] = 0;
        z[1] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        z[6] = 0;
        func_L00_00590790(obj);
    }
    base->a38[obj->f94] = 0;
    obj->h7E = 0;
}
