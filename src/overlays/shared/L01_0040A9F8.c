#include "common.h"

typedef struct VT { u8 pad[0x4C]; s32 (*f4C)(void *); } VT;

extern s32 D_0021DD9C;
extern void func_004E8DD0(void *, void *, s32, s32, void *, f32);
extern void *func_00510C30(void *);
extern s32 func_L00_00658420(s32);

void func_L01_0040A9F8(u8 *obj) {
    u8 *c;
    u8 *t;
    if (obj != 0 && obj[0x20] != 0xFE && obj[0x20] != 0xFD) {
        c = *(u8 **)(obj + 0xAC);
        if (c != 0) {
            t = *(u8 **)(c + 0x40);
            if (t != 0 && t[0x266D] != 0
                && (*(VT **)(t + 0x14))->f4C(t) == D_0021DD9C
                && *(s32 *)(c + 0x34) != 0
                && *(f32 *)(t + 0x2E20) > 0.0f) {
                s32 k = *(s32 *)(t + 0x25CC);
                if (k != 0x17) {
                    if (k != 0x18) {
                        if (k != 0x19) {
                            if (k != 0x1A) {
                                if (func_L00_00658420((*(VT **)(t + 0x14))->f4C(t)) == 0) {
                                    func_004E8DD0(c, c + 0x10, 0, 1, func_00510C30(t), 1.0f);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
