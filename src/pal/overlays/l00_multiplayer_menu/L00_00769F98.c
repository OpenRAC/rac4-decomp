#include "common.h"

extern const char D_L00_00221838[];
extern const char D_L00_00221840[];
extern const char D_L00_00221848[];
extern const char D_L00_00221850[];
extern s32 func_0011AB04(const char *text);
extern void *func_0011AFC8(void *dst, const void *src, u32 n);
extern char *func_0011A5D0(char *dst, const char *src);
extern s32 func_L00_00769700(const char *text, s32 width, const char *suffix, f32 scale);

void func_L00_00769F98(char *out, const char *text, s32 preserve, f32 scale, f32 width, f32 fraction)
{
    s32 length = func_0011AB04(text);
    const char *suffix = D_L00_00221838;
    const char *widthSuffix = D_L00_00221840;
    s32 keep;

    *out = '\0';
    if (preserve && length >= 2 && ((const u8 *)text)[length - 2] == '~' && ((const u8 *)text)[length - 1] == '2') {
        suffix = D_L00_00221848;
        widthSuffix = D_L00_00221850;
    }
    keep = func_L00_00769700(text, (s32)((f32)(s32)(width * 512.0f) * fraction), widthSuffix, scale);
    func_0011AFC8(out, text, keep);
    out[keep] = '\0';
    if (keep < length)
        func_0011A5D0(out, suffix);
}
