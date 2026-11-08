#include "common.h"

extern void func_00512D50(void *self, s32 a, s32 b, s32 en, s32 t);
extern void func_0051FCA8(void *self, s32 type, s32 arg);
extern s32 func_00453508(s16 *timer);
typedef struct {
    s16 active;
    s16 type;
    s16 timer;
    s16 arg;
} Slot_6379E8;
typedef struct {
    u8 pad0[1083];
    u8 b1083;
    u8 pad1[11552 - 1084];
    Slot_6379E8 slots[2];
} Self_6379E8;

/* from rac3-decomp's func_L39_0063A230 */
void func_L00_006C69F0(Self_6379E8 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_00453508(&self->slots[i].timer) == 2) {
            self->slots[i].active = 0;
            if (self->slots[i].type == 28) {
                func_00512D50(self, self->b1083, 1, 1, 50);
            } else {
                func_0051FCA8(self, self->slots[i].type, self->slots[i].arg);
            }
        }
    }
}
