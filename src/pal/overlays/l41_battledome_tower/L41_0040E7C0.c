#include "common.h"

typedef union {
    f32 scale;
    s32 scaleBits;
} ScaleWord;

typedef struct {
    u8 flag;
    u8 pad1[3];
    ScaleWord at4;
    s32 at8;
} Row7C0;

extern Row7C0 D_00375CD0[];
extern s32 D_00381550[];
extern s32 func_L00_006215A0(s32);
extern void func_00506B70(s32);
extern s32 func_00506BB8(void);
extern void func_L00_006A0CD0(s32, f32);

/* Writes one stride-12 row and, when the flag is clear, resets that slot's effect. */
void func_L41_0040E7C0(s32 index, s32 flag)
{
    u8 *flagp = &D_00375CD0[index].flag;
    ScaleWord *scale = &D_00375CD0[index].at4;
    s32 saved;
    s32 which;

    *flagp = (u8)flag;
    if (flag != 0)
        scale->scale = 0.8333333f;
    else
        scale->scaleBits = 0;
    D_00375CD0[index].at8 = 0;
    if (flag != 0)
        return;
    saved = func_00506BB8();
    func_00506B70(index);
    which = func_L00_006215A0(index);
    func_L00_006A0CD0(D_00381550[which], 1.0f);
    func_00506B70(saved);
}
