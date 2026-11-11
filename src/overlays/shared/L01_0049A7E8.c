/* cflags: -O2 -G8 */
#include "common.h"

typedef struct V_0049A7E8 {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    s32 unk20[3];
    s32 unk2C;
} V_0049A7E8;

typedef struct M_0049A7E8 {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0xAC - 0x21];
    V_0049A7E8 *unkAC;
} M_0049A7E8;

typedef struct G_0049A7E8 {
    u8 pad0[0x2E20];
    f32 unk2E20;
} G_0049A7E8;

M_0049A7E8 *D_00221CC0 = 0;
extern s32 D_0021DDB4;
extern s32 D_0024AD20[];
extern s16 D_0024AD4C[];
extern G_0049A7E8 *func_006658C0(s32);
extern s32 func_L00_005A00F8(void);
extern s32 func_L00_005BC980(void *);
extern s32 func_L01_0049A8F0(M_0049A7E8 *);
extern void func_L01_0049A9C0(M_0049A7E8 *);

void func_L01_0049A7E8(M_0049A7E8 *arg0) {
    V_0049A7E8 *v;
    M_0049A7E8 *m;
    u8 t;

    v = arg0->unkAC;
    if (func_L01_0049A8F0(arg0) != 0) {
        return;
    }
    m = D_00221CC0;
    if (m != arg0) {
        return;
    }
    if ((u32)(D_0021DDB4 - 1) < 2) {
        return;
    }
    if (func_L00_005A00F8() != 0) {
        return;
    }
    t = m->unk20;
    if (t == 1 && func_L00_005BC980(&v->unk20) != 0) {
        func_L00_005BC980(&v->unk2C);
        if (D_0024AD20[0] != t && D_0024AD4C[0] <= 0) {
            if (v->unk2C <= 0) {
                func_L01_0049A9C0(m);
            }
        } else if (v->unk2C < 300) {
            v->unk2C = 300;
        }
    }
    v->unk18 = func_006658C0(0)->unk2E20;
    v->unk1C = func_006658C0(1)->unk2E20;
}
