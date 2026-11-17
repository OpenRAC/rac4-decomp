/* Not matching yet: SIZE ours 192 / retail 188 (tools/try_func.py func_00128250 --diff) (tools/try_func.py func_00128250 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    void *f18;
} Type2;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u8 f6;
    u8 f7;
    s32 f8;
} Desc;

extern Type2 D_001A5C90;
extern char D_001A5CC0[];
extern char D_001A5E00[];
extern void func_00126E20(s32);
extern s32 func_00127C70(s32, void *, void *);
extern void *func_00127DC8(s32, s32, s32);
extern void func_00127E70();

int func_00128250(void)
{
    Desc *p;

    func_00126E20(0);
    D_001A5C90.f0 = func_00127C70(0x210, &D_001A5C90, (void *)func_00127E70);
    if (D_001A5C90.f0 < 0) {
        return 0;
    }
    p = (Desc *)((s32)D_001A5CC0 | 0x20000000);
    D_001A5C90.fC = 0;
    D_001A5C90.f4 = 0;
    D_001A5C90.f8 = 0;
    D_001A5C90.f14 = (s32)D_001A5E00 | 0x20000000;
    D_001A5C90.f10 = (s32)p;
    p->f4 = 0x210;
    p->f6 = 0x45;
    p->f7 = 0x48;
    p->f8 = 0;
    p->f2 = 0;
    D_001A5C90.f18 = func_00127DC8(0x100, 0x45, 0x210);
    return 1;
}
