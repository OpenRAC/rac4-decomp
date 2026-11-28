/* cflags: -G16 */
#include "common.h"
#include "pal/profile_001721E0.h"

f32 D_L41_00221388[4] = {0};
s32 D_L41_00221398[4] = {0};

s32 func_L41_0040E9B8(s32 index)
{
    s32 *entry = &D_L41_00221398[index];
    u32 clock = D_001721E0.region20.words.f218;
    s32 time = *entry;

    s32 elapsed = (s32)(clock - (u32)time);
    if (time == 0 || elapsed >= 2001)
        return 0;
    return 1;
}

extern f32 D_L41_00381580[];
extern f32 D_L41_00381598[];
extern s32 func_L00_006215A0(s32);
extern void func_00506B70(s32);
extern s32 func_00506BB8(void);
extern void func_00506000(s32, s32);
extern void func_L00_006A0BE8(s32, s32);
extern void func_L00_0069FF88(s32, s32);
extern void func_L00_0069FB20(s32, f32 *, f32 *);
extern f32 func_00475FB0(f32, f32, f32);
extern void func_L00_0069F6B8(s32, f32, f32);

/* Decays one slot float and, while it is in (0, 1), drives the tint calls. */
void func_L41_0040F900(s32 index) {
    s32 saved;
    s32 which;
    f32 value;
    f32 bumped;
    f32 outs[2];

    saved = func_00506BB8();
    func_00506B70(index);
    which = func_L00_006215A0(index);
    value = D_L41_00221388[index] - 0.05f;
    D_L41_00221388[index] = value;
    if (value <= 0.0f) {
        func_00506000(0xA0001, 0);
    } else if (value < 1.0f) {
        func_L00_006A0BE8(0xA0001, ((s32)(value * 128.0f) << 24) | 0x00D0D0D0);
        func_L00_0069FF88(0xA0001, (s32)(D_L41_00221388[index] * 64.0f) << 24);
        func_L00_0069FB20(0xA0001, &outs[0], &outs[1]);
        bumped = func_00475FB0(D_L41_00381580[which], D_L41_00381598[which], D_L41_00221388[index]) + 0.055f;
        outs[1] = bumped;
        func_L00_0069F6B8(0xA0001, outs[0], bumped);
    }
    func_00506B70(saved);
}
