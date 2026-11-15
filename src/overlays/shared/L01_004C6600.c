#include "common.h"

extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005F1180(void *, void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

// Spawns an object when the source's type is 0x20F6, initialises it from the source and returns it.
u8 *func_L01_004C6600(u8 *src) {
    u8 *obj;

    if (*(s16 *)(src + 0xBC) == 0x20F6) {
        obj = func_L00_005DD000(0x24DA, 0x20);
        if (obj != 0) {
            func_L00_005F1180(obj, src);
            *(s64 *)(obj + 0x38) = *(s32 *)(*(u8 **)(obj + 0xAC) + 0x438);
            *(u16 *)(obj + 0x74) = *(u16 *)(*(u8 **)(obj + 0xB8) + 0x74);
            *(u16 *)(obj + 0x34) &= 0xFFFC;
            *(u8 *)(obj + 0x31) = 1;
            func_L01_00591BD8(obj, 1, -1);
            return obj;
        }
    }
    return 0;
}
