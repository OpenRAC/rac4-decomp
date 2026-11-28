#include "pal/request_761c88.h"

extern s32 D_L00_003F41F0[];
extern s8 D_L00_00220C50[];
extern s8 D_L00_00220C60[];
extern s32 func_0011D920(s8 *dst, s8 *format, ...);
extern s32 func_L00_0070D8B0(PalRequest761C88 *);

/* Format an ID pair with optional text and submit the request. */
s32 func_L00_00712568(s32 id, u32 first, u32 second, s32 with_text, const char *text)
{
    PalRequest761C88 request;

    request.word_00 = D_L00_003F41F0[0];
    request.word_04 = 1;
    request.word_08 = id;
    if (with_text != 0) {
        func_0011D920((s8 *)request.text_1b, D_L00_00220C50, first, second, text);
    } else {
        func_0011D920((s8 *)request.text_1b, D_L00_00220C60, first, second);
    }
    return func_L00_0070D8B0(&request);
}
