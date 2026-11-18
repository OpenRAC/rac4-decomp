#include "common.h"

extern s32 func_00453CE8(void *p);
extern s32 func_0045E0A0(s32);
extern s32 func_L01_00516F58(void *object);
extern void func_L01_00516F88(void *object);
extern void func_L01_00517380(void *object);
extern void func_L01_00572880(s16 a, s32 b);
extern void func_00474368(u8 *object, s32 new_state, s32 param);
extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern s32 D_0021EC58;
extern s16 D_003AC108[];
extern s32 D_00269A40[];

/* Updates one object: on state 1 it sets the flag at +0xBE and runs its helpers, then clears the entries at D_003AC108 when the counter is high enough. */
void func_L01_00516E38(u8 *object)
{
    s32 *slot;
    s32 set;
    u8 flags;
    s32 count;
    s32 big;
    u8 *entry;
    u8 *end;

    slot = *(s32 **)(object + 0xAC);
    if (func_L01_00516F58(object) == 0) {
        if (object[0x20] == 1) {
            flags = object[0xBE];
            if (((flags ^ 1) & 1) != 0) {
                set = 1;
                object[0xBE] = (u8)(flags | 1);
            } else {
                set = 0;
            }
            if (set != 0) {
                *slot = 2250;
                if (D_0021E8A4 == 0 && D_0021E8A8 == 0) {
                    func_L01_00517380(object);
                }
            }
            if (func_00453CE8(slot) != 0) {
                func_L01_00516F88(object);
                func_00474368(object, 2, -1);
                count = D_0021EC58;
            } else {
                count = D_0021EC58;
            }
        } else {
            count = D_0021EC58;
        }
        big = count >= 8;
        if (big || D_00269A40[0] != 0) {
            entry = (u8 *)D_003AC108;
            end = entry + 0x78;
            do {
                if (func_0045E0A0(*(s16 *)entry) != 0) {
                    func_L01_00572880(*(s16 *)entry, 0);
                }
                entry += 0x14;
            } while ((s32)entry < (s32)end);
        }
    }
}
