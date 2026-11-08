#include "common.h"

extern void func_00513E28(u8 *p, s32 a, s32 b, s32 en, s32 t);
extern void func_00520E68(u8 *a0, s32 a1, s32 a2);
typedef struct {
    s16 active;
    s16 type;
    s16 timer;
    s16 arg;
} Slot_6CA3C0;
typedef struct {
    u8 pad0[1083];
    u8 b1083;
    u8 pad1[11552 - 1084];
    Slot_6CA3C0 slots[2];
} Self_6CA3C0;
extern s32 func_00453D20(s16 *timer);

/* PAL: from rac3-decomp's func_L39_0063A230 */
void func_L00_006CA3C0(Self_6CA3C0 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_00453D20(&self->slots[i].timer) == 2) {
            self->slots[i].active = 0;
            if (self->slots[i].type == 28) {
                ((void (*)(Self_6CA3C0 *self, s32 a, s32 b, s32 c, s32 d))func_00513E28)(self, self->b1083, 1, 1, 50);
            } else {
                ((void (*)(Self_6CA3C0 *self, s32 type, s32 arg))func_00520E68)(self, self->slots[i].type, self->slots[i].arg);
            }
        }
    }
}
