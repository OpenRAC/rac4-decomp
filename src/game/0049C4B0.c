#include "common.h"

extern u8 D_00306F2C[];
extern u8 D_003070D8[];
extern void func_0049BAB0(s32, s32);
extern void func_00504550(s32, void *, f32 *);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506060(u32 id, u32 child);

void func_0049C4B0(s32 slot, s32 offset, s32 id, s32 mode) {
    f32 pos[2];
    s32 saved_owner;
    s32 slot_bits;
    s32 first_id;
    s32 second_id;
    s32 base;
    s32 shared;
    u8 *rec;

    shared = 4;
    saved_owner = func_00505B20();
    func_00505AD8((mode != 0) ? shared : slot);
    if (slot == shared) {
        rec = D_00306F2C + offset * 0x34;
    } else {
        rec = D_003070D8 + (slot << 9) + offset * 0x34;
    }
    func_00504550(id, &pos[0], &pos[1]);
    slot_bits = slot << 6;
    base = 0x100001;
    first_id = slot_bits + base;
    *(f32 *)(rec + 0x14) += pos[0];
    *(f32 *)(rec + 0x18) += pos[1];
    func_00504550(first_id, &pos[0], &pos[1]);
    second_id = slot_bits + ((offset << 3) + base) + 1;
    *(f32 *)(rec + 0x14) -= pos[0];
    *(f32 *)(rec + 0x18) -= pos[1];
    func_00506060(id, second_id);
    func_00505DD0(first_id, second_id);
    func_00505AD8(saved_owner);
    func_0049BAB0(slot, offset);
}
