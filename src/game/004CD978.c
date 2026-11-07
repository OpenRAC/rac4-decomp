#include "common.h"

typedef struct {
    s8 f0;
    s32 f4;
    s32 f8;
} Entry;

extern s32 func_0045CB50(void);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32 player, s32 count);
extern void func_004A0BE8(void *arg0, s8 arg1);
extern void func_004A0BF0(void *param_a, s32 source, s32 param_b);
extern void func_004A1140(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5);
extern void func_004A1170(void *arg0);
extern void func_004A1240(void *, s32);
extern void func_004A1440(void *, void *, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004CE2F8(void);
extern u32 func_004CE428(s32 i);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506120(u32 id, u32 value);
extern void func_004CDE00(void);

extern unsigned int D_00171C08[];
extern u8 D_001CDAE8[];
extern s32 D_00221940;
extern u8 D_0030ECC0[];
extern Entry D_0030F6C0[];

void func_004CD978(void) {
    s32 i;
    s32 index;
    s32 *state;
    u8 *obj;
    u8 *p;
    unsigned int *bits;
    Entry *e;
    s32 hit;
    s32 key;
    u32 id;

    i = 0;
    index = func_00505B20();
    state = (s32 *)(D_0030ECC0 + index * 0x280);
    func_004CE2F8();
    obj = (u8 *)state + 0x210;
    state[0] = 1;
    state[1] = 0;
    func_004A1140(obj, state + 6, 0x15, func_004CDE00, 0x1E, 1);
    hit = *(s32 *)(obj + 0x2C);
    func_00505DD0(D_00221940, hit);
    func_004A0BF0(obj, func_004A1A60(&D_00221940, 9), 1);
    func_004A0BE8(obj, 1);
    func_0049D170(index, 0, func_004A1A60(&D_00221940, 0xA));
    func_0049D280(index, 1);
    key = D_00221940;
    func_0049C400(index, 0, key, func_004A1A60(&D_00221940, 0xA), 0);
    func_004A1170(obj);
    bits = D_00171C08;
    e = D_0030F6C0;
    do {
        hit = 0;
        id = func_004CE428(i);
        if ((bits[id >> 5] & (1 << (id & 0x1F))) || func_0045CB50() != 0) {
            hit = 1;
        }
        p = (u8 *)state + 0x210;
        if (hit) {
            func_004A1440(p, e, -1);
            e->f8 = i;
            e->f4 = i;
            e->f0 = 0;
        }
        i++;
        e++;
    } while (i < 0x15);
    if (*(s32 *)(p + 0x50) > 0) {
        func_004A1240(p, 0);
    }
    func_005054F8(func_004A1A60(&D_00221940, 3), 1);
    state[4] = func_00499CA0(D_001CDAE8, -1);
    func_005054F8(func_004A1A60(&D_00221940, 7), 1);
    func_00506120(func_004A1A60(&D_00221940, 7), state[4]);
    state[5] = func_00499CA0(D_001CDAE8 - 0x30, -1);
    func_005054F8(func_004A1A60(&D_00221940, 1), 1);
    func_00506120(func_004A1A60(&D_00221940, 1), state[5]);
    state[2] = 7;
}
