#include "common.h"

typedef struct {
    u8 pad0[0x70];
    s32 x70;
    s32 x74;
    u8 pad78[0xC];
    s16 n;
    u8 pad86[0x16A];
    u8 *mobys[1];
} Arena;

extern Arena D_0023F600;
extern u8 *D_003660F8[];
extern s32 D_0021DE10;
extern void func_L00_00596A28(s32, s32, s32, s32);
extern void func_L00_00598118(s32);
extern void func_L01_0052CE98(void);

void func_L01_005334B0(void) {
    u8 *moby;
    u8 *m;
    u8 *q;
    s32 i;
    s32 j;
    s32 id;

    for (i = 0; i < D_0023F600.n; i++) {
        moby = D_0023F600.mobys[i];
        if (moby != NULL) {
            id = *(s16 *)(moby + 0xBC);
            if (id == 0x216A || id == 0x2691 || (id == 0x2429 && D_0021DE10 == 0x2574) || id == 0x20FD || id == 0x2703 || id == 0x2505) {
                func_L00_00596A28(i, 0x96, 0, 0);
            }
            if (*(s16 *)(moby + 0xBC) == 0x216A || *(s16 *)(moby + 0xBC) == 0x2691) {
                *(u16 *)(D_0023F600.mobys[i] + 0x74) |= 0x1000;
            }
            if (*(s16 *)(moby + 0xBC) == 0xA) {
                m = D_0023F600.mobys[i];
                if (D_0023F600.x70 == 2) {
                    *(u16 *)(m + 0x74) |= 0x1000;
                } else {
                    *(u16 *)(m + 0x74) |= 0x1002;
                }
                func_L00_00596A28(i, 0x6E, 0x80306629, 0x8058B856);
            }
            if (*(s16 *)(moby + 0xBC) == 0x243D) {
                func_L00_00596A28(i, 0x168, 0xC0808080, 0x80505050);
            }
            if (*(s16 *)(moby + 0xBC) == 0x247F || *(s16 *)(moby + 0xBC) == 0x24D9 || *(s16 *)(moby + 0xBC) == 0x24D5) {
                func_L00_00596A28(i, 0x5A, 0xFFC0C0C0, 0xB0505050);
            }
        }
    }
    func_L01_0052CE98();
    if (D_0023F600.x70 == 0x14 && D_0023F600.x74 < 0xA0) {
        func_L00_00598118(0);
    }
    if (D_0023F600.x70 == 0x15 && D_0023F600.x74 >= 0x65) {
        func_L00_00598118(0);
    }
    func_L00_00598118(0);
    for (j = 0, q = D_003660F8[0]; j < 10; q = D_003660F8[++j]) {
        if (q != NULL) {
            (*(u8 **)(q + 0x2EF0))[0x31] = 0;
        }
    }
}
