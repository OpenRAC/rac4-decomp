#include "common.h"
typedef struct {
    u8 unknown0[0x28];
    u8 has_amount;
} Descriptor;
extern s32 D_0021EE54;
extern s32 func_0054A308(void *inventory, s32 item);
extern void func_005491F8(void *inventory, s32 item, s32 level);
extern Descriptor *func_0054A290(s32 item, s32 retained_selector);
extern s32 func_0054B7D0(s32 item, s32 slot);
extern s32 func_0054BCF0(void *inventory, s32 item, s32 weapon);
extern s32 func_0054B120(void *inventory, s32 weapon);
extern s32 func_0054B7F8(void *inventory, s32 item, s32 weapon);
extern void func_0054B288(void *inventory, s32 weapon, s32 amount, s32 item);
extern s32 func_00549368(void *inventory, s32 item);
extern s32 func_00549398(void *inventory, s32 item);
extern void func_00549330(void *inventory, s32 item, s32 amount);
void func_0054A360(void *inventory, s32 item, s32 level, s32 force, s32 skip_existing)
{
    Descriptor *descriptor;
    s32 weapon;
    if (func_0054A308(inventory, item))
        return;
    func_005491F8(inventory, item, level);
    descriptor = func_0054A290(item, 0);
    weapon = func_0054B7D0(item, 0);
    if (D_0021EE54 != 1 && level == 0 &&
        func_0054BCF0(inventory, item, weapon) == 0) {
        if (skip_existing == 0 && func_0054B120(inventory, weapon)) {
            func_0054B7F8(inventory, item, weapon);
        } else {
            func_0054B288(inventory, weapon, -1, item);
        }
    }
    if (descriptor->has_amount) {
        if (func_00549368(inventory, item) == 0 || force) {
            func_00549330(inventory, item, func_00549398(inventory, item));
        }
    }
}
