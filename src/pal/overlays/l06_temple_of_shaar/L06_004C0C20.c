#include "common.h"

extern s32 func_00540958(void *);
extern void *D_00362AB8[];

// Returns 1 if one of the first ten entries of D_00362AB8 passes a kind test, else 0.
s32 func_L06_004C0C20(void) {
    u8 *obj;
    s32 i;
    s32 kind;

    i = 0;
    obj = D_00362AB8[0];
    while (i < 10) {
        if (obj != 0) {
            if (*(f32 *)(obj + 0x2E20) <= 0.0f) {
                return 1;
            }
            kind = *(s32 *)(obj + 0x25CC);
            if (kind == 0x39 || kind == 0x68 || kind == 0x6A || kind == 0x76 || kind == 0x7A || kind == 0x7B || kind == 0x7E || kind == 0x7F || kind == 0x94 || kind == 0x99) {
                return 1;
            }
            if (func_00540958(obj) != 0) {
                return 1;
            }
        }
        i++;
        obj = D_00362AB8[i];
    }
    return 0;
}
