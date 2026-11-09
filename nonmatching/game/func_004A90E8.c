/* Not matching yet: BYTES 28/428 (tools/try_func.py func_004A90E8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad0[0x8C];
    s32 f8C;
    u8 pad90[0xB8 - 0x90];
} Type1;

typedef struct {
    u8 pad0[0x26E4];
    s32 h;
} Type2;

extern s32 func_004989F0(s32 kind);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004A8B10(s32 slot, s32 kind);
extern void func_00504F68(s32, s32);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00547A98(s32 arg0);
extern s32 func_00548DA0();
extern s32 func_0054A7E0(s32, s32);

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_003D1760[];
extern s32 D_003D17A0[];
extern s32 D_00221650;
extern Type1 D_00308108[];

void func_004A90E8(void) {
    s32 i = 0;
    s32 index = func_00505B20();
    Type1 *p = &D_00308108[index];
    Type2 *obj = func_00510BE8(index);
    s32 *a = (s32 *)((u8 *)D_003D17A0 + (p->f8C << 5));
    s32 *b = D_003D1760;

    do {
        if (*a != 0 && (u8)func_00548DA0(obj->h, *a) &&
            (D_0021EDD4 != 0 || D_0021EDD8 != 0 || func_00547A98(i) == 0)) {
            s32 n = func_0054A7E0(obj->h, *a);
            s32 h;
            func_00504F68(func_004A1A60(&D_00221650, *b + 0x18), n > 0);
            h = func_004A1A60(&D_00221650, *b + 0x18);
            func_00505328(h, func_004989F0(n));
            func_004A8B10(func_004A1A60(&D_00221650, *b + 0xF), *a);
        } else {
            func_00504F68(func_004A1A60(&D_00221650, *b + 0x18), 0);
            func_004A8B10(func_004A1A60(&D_00221650, *b + 0xF), 0);
        }
        i++;
        b++;
        a++;
    } while (i < 8);
}
