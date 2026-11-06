#include "common.h"

typedef struct Tint {
    s16 timer;
    s16 kind;
    s32 color;
    u32 original;
} Tint;
extern Tint *func_00477870(u8 *object);
extern void func_00470990(u8 *object, u32 red, u32 green, u32 blue);
extern void func_004709A8(const u8 *object, u32 *red, u32 *green, u32 *blue);

void func_004778A8(u8 *object, s32 kind, s32 color, Tint *tint)
{
    u32 red, green, blue;

    if (tint == 0) {
        tint = func_00477870(object);
        if (tint == 0) {
            return;
        }
    }
    if (kind == tint->kind && (color == tint->color || tint->timer < 17)) {
        return;
    }
    if (color == 0) {
        if (kind == 1) {
            color = 0x800000F0;
        } else if (kind == 2) {
            color = 0x80F00000;
        } else if (kind == 3) {
            color = 0x8010A0A0;
        } else if (kind == 4) {
            color = 0x80F0F0F0;
        } else if (kind == 5) {
            color = 0x80804000;
        } else if (kind == 6) {
            color = 0x80808080;
        } else if (kind == 0) {
            color = tint->original;
        }
    }
    if (kind == 0) {
        if (tint->kind != 0) {
            blue = ((u8 *)&tint->original)[2];
            green = ((u8 *)&tint->original)[1];
            red = ((u8 *)&tint->original)[0];
            func_00470990(object, red, green, blue);
        } else {
            goto capture;
        }
    } else if (tint->kind == 0) {
    capture:
        func_004709A8(object, &red, &green, &blue);
        tint->original = ((u32)object[0x23] << 24) | (blue << 16) | (green << 8) | red;
    }
    tint->color = color;
    tint->kind = kind;
    tint->timer = 0;
}
