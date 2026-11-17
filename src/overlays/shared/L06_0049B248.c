#include "common.h"

extern s32 func_L00_006F3958(void *);
extern void *D_362B38[];

// Returns 1 if one of the first ten entries of D_362B38 passes a kind test, else 0.
s32 func_L06_0049B248(void) {
    u8 *obj;
    s32 i;
    s32 kind;

    i = 0;
    obj = D_362B38[0];
    while (i < 10) {
        if (obj != 0) {
            if (*(f32 *)(obj + 0x2E20) <= 0.0f) {
                return 1;
            }
            kind = *(s32 *)(obj + 0x25CC);
            if (kind == 0x39 || kind == 0x68 || kind == 0x6A || kind == 0x76 || kind == 0x7A || kind == 0x7B || kind == 0x7E || kind == 0x7F || kind == 0x94 || kind == 0x99) {
                return 1;
            }
            if (func_L00_006F3958(obj) != 0) {
                return 1;
            }
        }
        i++;
        obj = D_362B38[i];
    }
    return 0;
}
