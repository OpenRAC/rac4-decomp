#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type2;

typedef struct {
    u8 pad0[0x5C];
    s32 f5C;
    u8 pad1[0x120 - 0x60];
    s32 f120;
    Type2 *f124[0x100];
    s32 f524;
    s32 f528;
    s32 f52C;
} Type1;

// Set the selected index +0x524 from value (-1 and -2 search for an entry whose type is not 3), then copy it to +0x528.
void func_L00_00712CD8(Type1 *obj, s32 value) {
    s32 i;

    if (value == -1) {
        obj->f524 = value;
        obj->f52C = 0;
        for (i = 0; i < obj->f120; i++) {
            if (obj->f124[i]->f4 != 3) {
                break;
            }
        }
        if (i < obj->f120) {
            obj->f524 = i;
        }
    } else if (value == -2) {
        obj->f524 = -1;
        obj->f52C = obj->f120 - obj->f5C;
        for (value = obj->f120 - 1; value >= 0; value--) {
            if (obj->f124[value]->f4 != 3) {
                break;
            }
        }
        if (value >= 0) {
            obj->f524 = value;
        }
    } else if (value >= 0 && value < obj->f120) {
        obj->f524 = value;
    }
    obj->f528 = obj->f524;
}
