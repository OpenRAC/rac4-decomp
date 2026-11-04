#include "common.h"

typedef struct {
    s32 total;
    s32 dmg;
    s32 pct;
    s32 timer;
} Vars;

extern u8 *D_003660F8[10];
extern s32 D_0021DE98;
extern s32 D_0021EC58;
extern u8 D_003BC150[];
extern void func_L00_0065BB60(s32, s32);
extern s32 func_L01_0062B6C0(s32, u8 *);
extern s16 func_004E2EF0(s32, s32, u8 *);
extern u8 *func_L00_005C6790(void);
extern void func_00453F30(void *, const void *, s32);
extern s32 func_00453CE8(s32 *);

// First call: func_L00_0065BB60(i, -1) for each present player. Then a countdown in
// the moby's vars (+0xC, reset to (vars[0] * 5 + 2) / 6); when it runs out, every player's
// +0x2E20 value drops by vars[1], or by vars[2]% of its +0x2F24 value.
void func_L01_004ABE88(u8 *moby) {
    Vars *vars = *(Vars **)(moby + 0xAC);
    s32 first;
    s32 i;
    s32 j;
    u8 *p;
    u8 *o;

    if ((moby[0xBE] ^ 1) & 1) {
        moby[0xBE] |= 1;
        first = 1;
    } else {
        first = 0;
    }
    if (first) {
        u8 *q;

        for (i = 0, q = D_003660F8[0]; i < 10; q = D_003660F8[++i]) {
            if (q != NULL) {
                func_L00_0065BB60(i, -1);
            }
        }
    }
    if (func_L01_0062B6C0(0, moby) == 0) {
        func_004E2EF0(0, 4, moby);
    }
    o = func_L00_005C6790();
    if (o != NULL) {
        u8 *ov = *(u8 **)(o + 0xAC);

        if (ov != NULL) {
            ov[8] = 0x11;
        }
        func_00453F30(D_003BC150 + 0x1240, D_003BC150 + 0xED4, 0x124);
        if ((D_0021DE98 == 1 || D_0021DE98 == 0x15) && D_0021EC58 == 0x24) {
            D_003BC150[0x1294] = 0x80;
            D_003BC150[0x1295] = 0;
        } else {
            D_003BC150[0x1295] = 0x80;
            D_003BC150[0x1294] = 0;
        }
        D_003BC150[0x1296] = 0;
        D_003BC150[0x1297] = 0x30;
    }
    if (vars->timer == -1) {
        vars->timer = (vars->total * 5 + 2) / 6;
    } else if (func_00453CE8(&vars->timer)) {
        vars->timer = -1;
        for (j = 0, p = D_003660F8[0]; j < 10; p = D_003660F8[++j]) {
            if (p != NULL) {
                if (vars->dmg > 0) {
                    *(f32 *)(p + 0x2E20) -= (f32)vars->dmg;
                } else if (vars->pct > 0) {
                    *(f32 *)(p + 0x2E20) -= (f32)vars->pct * 0.01f * *(f32 *)(p + 0x2F24);
                }
            }
        }
    }
}
