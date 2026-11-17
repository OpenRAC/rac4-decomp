#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef struct Obj { char pad[0xBC]; s16 fBC; } Obj;
extern u8 D_242340[];
extern u8 *D_3660F8[];
extern void func_L01_0050F848(s32 arg0, void *arg1);

// Picks the target object for arg1, then copies a 16-byte value into arg0.
s32 func_L01_0050F548(u8 *arg0, u8 *arg1) {
    u8 *g = D_242340;
    Obj *obj = *(Obj **)(g + 0x18);
    if (obj != 0) {
        if (obj->fBC == 0x2510 || obj->fBC == 0x2689) {
            return 0;
        }
        *(Obj **)(arg1 + 0x10) = obj;
        if (obj->fBC == 0x23F7) {
            s32 i;
            u8 **p = D_3660F8;
            u8 *e = *p;
            for (i = 0; i < 10; i++) {
                if (e != 0 && *(s32 *)(e + 0x2EF0) == *(s32 *)(arg1 + 0x10)) {
                    *(s16 *)(e + 0x412) = 0x32;
                }
                p++;
                e = *p;
            }
        }
        func_L01_0050F848((s32)arg0, arg1);
        *(u128 *)(arg0 + 0x10) = *(u128 *)(arg1 + 0x30);
    } else {
        *(u128 *)(arg0 + 0x10) = *(u128 *)(g + 0x20);
    }
    return 1;
}
