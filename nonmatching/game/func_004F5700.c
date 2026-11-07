/* Not matching yet: BYTES 17/360 (tools/try_func.py func_004F5700 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 b[8];
} Type1;

typedef struct {
    s32 f0;
    Type1 f4;
    u8 padC[0x44 - 0xC];
    s8 f44[8];
} Type2;

extern Type2 D_00328990;
extern s8 D_00328994[];
extern char D_002209A0[];
extern void *memcpy(void *, const void *, unsigned int);
extern s8 D_002209A8[];
extern s32 D_001D3F40[];
extern s32 D_001DFCF4;
extern s32 D_002211CC;

extern void func_004E7E58(s32, s32, s32, s32);
extern void func_00448C68(s32);
extern void func_00448D98(void);
extern void func_0011A518(void *, s32, s32);
extern u32 func_0011AB04(s8 *);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_00449E98(int, int, int, int, u64);
extern void func_00455E78(f32, f32, void *, u64, void *, s32, u64);
extern void func_004576A0(void *a, int b, int c, int d, int e, int f, int g, int h, int i);

void func_004F5700(void)
{
    u8 buf[0x20];
    s8 *s;
    s32 len;
    Type2 *p = &D_00328990;

    func_004E7E58(p->f0, D_001DFCF4, 0x200, 0x200);
    func_00448C68(1);
    memcpy(&p->f4, D_002209A0, 8);
    if ((D_002211CC & 3) == 0) {
        s = p->f44;
        if (func_0011AB04(s) < 6) {
            s[func_0011AB04(s)] = '.';
            s[func_0011AB04(s) + 1] = 0;
        } else {
            func_0011A518(s, 0, 7);
        }
    }
    func_0011D920(D_00328994, D_002209A8, D_00328994, D_00328994 + 0x40);
    func_004576A0(buf, 0, D_001D3F40[1], 0, D_001D3F40[0], 0x14D, 0xE3, 0x10, 2);
    len = func_0011AB04(D_00328994);
    func_00455E78(1.0f, 1.0f, buf, 0x80808080, D_00328994, len, 0x80000000);
    func_00448D98();
    func_00449E98(0x10E, 0x12C, 0x15E, 0x1D6, (s32)0x80000000);
}
