/* Not matching yet: BYTES 3/604 (tools/try_func.py func_004CB938 --diff). Not part of the build. */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 _pC[0x10];
    s32 f1C;
    u8 _p20[0x44];
} Type1;

extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004CBB98(s32 id);
extern s32 func_004CC7A0(s32 arg0);
extern s32 func_004CC8A8(s32 arg0);
extern void func_00504F68(s32, s32);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00506120(u32 id, u32 value);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_003D2738[];
extern s32 D_001CE360[];
extern s32 D_00221920;
extern Type1 D_0030EAA0[];

void func_004CB938(void) {
    s32 id = func_00505B20();
    Type1 *e = &D_0030EAA0[id];
    s32 i;
    s32 one;

    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        func_005054F8(func_004A1A60(&D_00221920, 0x35), 1);
        e->f1C = func_00499CA0(D_001CE360, -1);
        func_00506120(func_004A1A60(&D_00221920, 0x35), e->f1C);
        func_00504F68(func_004A1A60(&D_00221920, 0x35), 1);
    } else {
        func_00504F68(func_004A1A60(&D_00221920, 0x35), 0);
    }
    for (i = 0, one = 1; i < 8; i++) {
        if (func_004CC7A0(i) != 0) {
            func_00504F68(func_004A1A60(&D_00221920, D_003D2738[i]), 1);
            if (D_0021EDD4 == 0 && D_0021EDD8 == one && i < 4) {
                func_00505328(func_004A1A60(&D_00221920, D_003D2738[i]), 0x80404040);
                func_005054F8(func_004A1A60(&D_00221920, D_003D2738[i]), 0x754B);
            } else {
                s32 h;
                if (e->f4 < 0) {
                    e->f4 = i;
                }
                func_00505328(func_004A1A60(&D_00221920, D_003D2738[i]), 0x80808080);
                h = func_004A1A60(&D_00221920, D_003D2738[i]);
                func_005054F8(h, func_004CC8A8(i));
            }
        } else {
            func_00504F68(func_004A1A60(&D_00221920, D_003D2738[i]), 0);
        }
    }
    if (e->f4 < 0) {
        e->f4 = 8;
    }
    func_004CBB98(id);
}
