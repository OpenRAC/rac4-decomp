#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *D_00270AA0[];
extern s32 D_0021EE54;
extern u8 *D_003367B8[10];

extern u8 *func_00491450(s32);
extern f32 func_00472EB8(f32, f32);
extern s16 func_00472E70(s32, s32);
extern f32 func_00474FA0(u128, s32);
extern f32 func_00472F70(void);

// Takes a particle of type 0x22 from func_00491450 and fills it like func_004938D0: arg2, colour
// bytes 0x44, a random size (0.75..1.25 * scale), 5250 at +0xC, a random byte around -0x80, the byte
// D_00270AA0[0] points to, and a random value 0x3A..0x75. Its height is the given one, or (when it is
// -1) taken from func_00474FA0 or from the 10 entries of D_003367B8; then random spin and rates, vel
// and pos.
u8 *func_004936E0(u128 *pos, f32 *vel, s32 arg2, f32 scale, f32 height) {
    u8 *p = func_00491450(0x22);
    f32 *vars;
    s32 i;
    u8 *pl;

    if (p != NULL) {
        *(s32 *)(p + 4) = arg2;
        p[1] = 0;
        vars = (f32 *)(p + 0x20);
        p[9] = 0x44;
        p[3] = 0x44;
        vars[3] = func_00472EB8(0.75f, 1.25f) * scale;
        *(f32 *)(p + 0xC) = 5250.0f;
        p[8] = func_00472E70(-10, 10) - 0x80;
        p[2] = *D_00270AA0[0];
        *(s16 *)(p + 0xA) = func_00472E70(0x3A, 0x75);
        if (height == -1.0f) {
            if (D_0021EE54 == 0) {
                for (i = 0, pl = D_003367B8[0]; i < 10; pl = D_003367B8[++i]) {
                    if (pl != NULL) {
                        if (*(s32 *)(pl + 0x25CC) == 0x30) {
                            vars[4] = *(f32 *)(pl + 0xA8) + 0.4f;
                        } else {
                            vars[4] = *(f32 *)(pl + 0x2E0);
                        }
                    }
                }
            } else {
                vars[4] = func_00474FA0(*pos, 0);
            }
        } else {
            vars[4] = height;
        }
        vars[5] = func_00472F70();
        vars[6] = func_00472EB8(0.03490659f, 0.13962635f);
        vars[7] = func_00472EB8(0.010000001f, 0.028f);
        vars[0] = vel[0];
        vars[1] = vel[1];
        vars[2] = vel[2];
        *(u128 *)(p + 0x10) = *pos;
    }
    return p;
}
