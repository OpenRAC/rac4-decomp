#include "common.h"

typedef struct Type1 Type1;

typedef struct {
    u8 pad[0x33C];
    Type1 *f33C;
} Type2;

struct Type1 {
    u8 pad[0x20];
    u8 f20;
    u8 pad21[0x53];
    s16 f74;
    u8 pad76[0x36];
    Type2 *fAC;
    u8 padB0[0xC];
    s16 fBC;
};

typedef struct {
    u8 pad[0x3C];
    s16 f3C;
} Type3;

extern s32 D_0021EE54;
extern void *func_0054A290(s32 selector, s32 mode);
extern s32 func_004EE7E0(Type1 *object);

// Select the state word for the requested object and progression level.
void func_0054ADA8(Type1 *object, s32 selector, s32 level)
{
    Type3 *description = func_0054A290(selector, 0);
    s32 threshold = D_0021EE54 == 1 ? 1 : 9;

    if (selector == 15) {
        Type1 *linked;

        if (object->fBC != 0x2106 || func_004EE7E0(object) != 0)
            return;
        linked = object->fAC->f33C;
        if (!linked || linked->f20 == 0xFE || linked->f20 == 0xFD)
            return;
        if (linked->fBC != 0x210B)
            return;
        object = linked;
    }

    object->f74 = 0;
    switch (selector) {
    case 2:
        if (level < threshold) {
            object->f74 = 0;
            return;
        }
        object->f74 = 1;
        break;
    case 3:
        if (level < threshold)
            object->f74 = 3;
        else
            object->f74 = 12;
        break;
    case 6:
        if (level < threshold) {
            object->f74 = 0;
            return;
        }
        object->f74 = 12;
        break;
    case 7:
        if (level >= threshold)
            goto set_six;
        object->f74 = 4;
        return;
    case 4:
        if (level < threshold)
            object->f74 = 3;
        else
            object->f74 = 12;
        break;
    case 8:
        if (level < threshold)
            object->f74 = 1;
        else
            object->f74 = 12;
        break;
    case 5:
        if (level < threshold)
            object->f74 = 1;
        else
            object->f74 = 2;
        break;
    case 15:
        if (level >= threshold) {
            object->f74 = 24;
            break;
        }
        if (D_0021EE54 != 1) {
            object->f74 = 3;
            break;
        }
        object->f74 = 7;
        break;
    case 9:
        if (object->fBC == 0x24F2) {
            if (level >= threshold) {
                object->f74 = 1;
                break;
            }
            object->f74 = 0;
            return;
        }
        if (object->fBC != description->f3C)
            return;
        if (level >= threshold)
            object->f74 = 7;
        else
            object->f74 = 6;
        break;
    case 10:
        return;
    case 11:
        return;
    case 12:
        return;
    case 13:
        return;
    case 14:
        return;
    default:
        return;
    }
    return;
set_six:
    object->f74 = 6;
}
