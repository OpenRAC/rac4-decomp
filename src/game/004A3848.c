#include "common.h"

typedef struct {
    s32 unk0;
    f32 timer;
} Type1;

typedef struct {
    f32 timer;
    s32 unk4;
} Type2;

extern u8 func_004A7C30(s32 arg0);
extern void func_00504F68(s32, s32);
extern Type1 D_00307A68[];
extern Type2 D_00307A94[][5];
extern s32 D_00307B30[];

s32 D_0021F678 = 0;

void func_004A3848(void) {
    s32 active = 0;
    s32 i;
    s32 j;

    if (D_0021F678 >= 2) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                Type2 *e = &D_00307A94[i][j];
                if (e->timer > 0.0f) {
                    active = 1;
                    func_00504F68(i * 3 + 0xE0003 + j, func_004A7C30(i) ^ 1);
                    e->timer -= 0.016666668f;
                } else {
                    func_00504F68(i * 3 + 0xE0003 + j, 0);
                }
            }
        }
    } else {
        s32 k;
        for (k = 0; k < 5; k++) {
            if (D_00307A68[k].timer > 0.0f) {
                active = 1;
                func_00504F68(k + 0xE0003, func_004A7C30(k) ^ 1);
                D_00307A68[k].timer -= 0.016666668f;
            } else {
                func_00504F68(k + 0xE0003, 0);
            }
        }
    }
    if (active == 0) {
        D_00307B30[9] &= ~4;
    }
}
