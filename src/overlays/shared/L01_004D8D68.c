#include "common.h"

extern void func_L01_004D88A0(void);
extern void func_00591BD8(void *o, u8 state, s32 type);

// Set the object's state byte at +0x20 to 5, unless it is unset (then respawn) or already 4.
void func_L01_004D8D68(u8 *object) {
    if (*(u8 *)(object + 0x20) == 0) {
        func_L01_004D88A0();
    }
    if (*(u8 *)(object + 0x20) != 4) {
        func_00591BD8(object, 5, -1);
    }
}
