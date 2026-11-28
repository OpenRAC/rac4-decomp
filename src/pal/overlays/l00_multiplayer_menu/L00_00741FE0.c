#include "common.h"
#include "pal/request_761c88.h"

extern s32 func_0011D9A8(void *, const char *, ...);
extern char D_00221238[];

s32 D_002211C8 = -1;
s32 D_002211CC = -1;

u8 D_002211D1 = 0;
u8 D_002211D0 = 0;

/* PAL: from rac3-decomp's func_L04_003796C8 */
s32 func_L00_00741FE0(void) {
    D_002211D0 = 1;
    D_002211D1 = 1;
    return 2;
}

/* Scan a request's text into two words; store -1 in both when the scan does not return 2. */
s32 func_L00_007420A0(s32 unused, PalRequest761C88 *request) {
    s32 count;

    count = func_0011D9A8(request->text_1b, D_00221238, &D_002211C8, &D_002211CC);
    if (count != 2) {
        D_002211C8 = -1;
        D_002211CC = -1;
    }
    D_002211D1 = 0;
    return 2;
}
