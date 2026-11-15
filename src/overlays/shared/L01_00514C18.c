#include "common.h"

extern s32 func_L00_005BC980(void *p);
extern s32 func_L00_005C9710(s32);
extern s32 func_L01_00514D38(void *object);
extern void func_L01_00514D68(void *object);
extern void func_L01_00515160(void *object);
extern void func_L01_0056FC88(s16 a, s32 b);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 D_0021E824;
extern s32 D_0021E828;
extern s32 D_0021EBD8;
extern s16 D_003AC108[];
extern s32 D_269940[];

/* Updates one object: on state 1 it sets the flag at +0xBE and runs its helpers, then clears the entries at D_003AC108 when the counter is high enough. */
void func_L01_00514C18(u8 *object)
{
    s32 *slot;
    s32 set;
    u8 flags;
    s32 count;
    s32 big;
    u8 *entry;
    u8 *end;

    slot = *(s32 **)(object + 0xAC);
    if (func_L01_00514D38(object) == 0) {
        if (object[0x20] == 1) {
            flags = object[0xBE];
            if (((flags ^ 1) & 1) != 0) {
                set = 1;
                object[0xBE] = (u8)(flags | 1);
            } else {
                set = 0;
            }
            if (set != 0) {
                *slot = 0xA8C;
                if (D_0021E824 == 0 && D_0021E828 == 0) {
                    func_L01_00515160(object);
                }
            }
            if (func_L00_005BC980(slot) != 0) {
                func_L01_00514D68(object);
                func_L01_00591BD8(object, 2, -1);
                count = D_0021EBD8;
            } else {
                count = D_0021EBD8;
            }
        } else {
            count = D_0021EBD8;
        }
        big = count >= 8;
        if (big || D_269940[0] != 0) {
            entry = (u8 *)D_003AC108;
            end = entry + 0x78;
            do {
                if (func_L00_005C9710(*(s16 *)entry) != 0) {
                    func_L01_0056FC88(*(s16 *)entry, 0);
                }
                entry += 0x14;
            } while ((s32)entry < (s32)end);
        }
    }
}
