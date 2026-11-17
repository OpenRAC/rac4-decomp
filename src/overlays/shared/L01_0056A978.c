#include "common.h"

extern void func_L01_0056DD58(void *, f32 *, f32 *, f32 *, f32 *, s32, s32);
extern s32 func_L01_00572A68(s32 arg0, void *arg1);
extern s32 func_L01_00573BC0(u8 *a0, f32 x, f32 y, f32 z, f32 w);
extern u8 *D_222C18;
extern u8 *D_222DA0;
extern u8 D_24B080[];

/* Adds the positions of every node in path n to the owner's list. */
void func_L01_0056A978(u8 *a0, s32 n) {
    f32 v[4];
    u8 *path;
    s32 i;

    i = 0;
    path = D_222C18 + (n * 0x30 + 0x20);
    for (; i < *(s16 *)(path + 0x12); i++) {
        func_L01_0056DD58(D_222DA0 + ((*(s32 **)(path + 0x20))[i] << 7), &v[0], &v[1], &v[2], &v[3], 0, 0);
        func_L01_00573BC0(D_24B080, v[0], v[1], v[2], v[3]);
        func_L01_00572A68(*(s32 *)(a0 + 0x3F8), D_24B080);
    }
}
