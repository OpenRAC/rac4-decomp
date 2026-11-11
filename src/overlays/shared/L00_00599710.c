/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 func_00596A28(s32, s32, u32, u32);
extern s32 func_00598118(s32);
extern s32 D_0021DE10;
struct Type1 {
    u8 f0[0x70];
    s32 f70;
    u8 f74[0x10];
    s16 f84;
};
extern struct Type1 D_0023BE00[];
extern u8 *D_00343E78[];
#define ID(p) (*(s16 *)((p) + 0xbc))
#define FLAGS(p) (*(u16 *)((p) + 0x74))

void func_L00_00599710(void) {
    s32 i;

    u8 *m;
    i = 0;
    if (D_0023BE00[0].f84 > 0) {

        do {
            m = ((u8 **)((u8 *)D_0023BE00 + 0x1f0))[i];
            if (m) {
                if (ID(m) == 0x216a || ID(m) == 0x2691 ||
                    (ID(m) == 0x2429 && D_0021DE10 == 0x2574) || ID(m) == 0x20fd ||
                    ID(m) == 0x2703 || ID(m) == 0x2505)
                    func_00596A28(i, 0x96, 0, 0);
                if (ID(m) == 0x216a || ID(m) == 0x2691)
                    FLAGS(((u8 **)((u8 *)D_0023BE00 + 0x1f0))[i]) |= 0x1000;
                if (ID(m) == 10) {
                    u8 *p = ((u8 **)((u8 *)D_0023BE00 + 0x1f0))[i];
                    if (D_0023BE00[0].f70 == 2)
                        FLAGS(p) |= 0x1000;
                    else
                        FLAGS(p) |= 0x1002;
                    func_00596A28(i, 0x6E, 0x80306629, 0x8058b856);
                }
                if (ID(m) == 0x243d)
                    func_00596A28(i, 0x168, 0xc0808080, 0x80505050);
                if (ID(m) == 0x247f || ID(m) == 0x24d9 || ID(m) == 0x24d5)
                    func_00596A28(i, 0x5A, 0xffc0c0c0, 0xb0505050);
            }
            i++;
        } while (i < D_0023BE00[0].f84);
    }
    func_00598118(0);
    {
        u8 **p = D_00343E78;
        s32 n = 9;
        u8 *v = *p;
        do {
            p++;
            n--;
            if (v)
                (*(u8 **)(v + 0x2ef0))[0x31] = 0;
            v = *p;
        } while (n >= 0);
    }
}
