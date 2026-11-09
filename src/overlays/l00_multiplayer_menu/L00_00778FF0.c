#include "common.h"

extern s32 func_0011D9A8(void *, const char *, ...);
extern u8 D_002218B8[];
extern u8 D_002218C0[];

// Classify a two-letter prefix of the text: 'CY' gives 1, 'CR' 4, 'CC' 2, 'H' 6
// and anything else 8; the text after the prefix goes to func_0011D9A8 with one
// of two buffers (D_002218C0 for 'CC', (const char *)D_002218B8 for the others).
s32 func_L00_00778FF0(s32 unused, u8 *text, u32 *out1, u32 *out2) {
    s32 result = 8;
    u8 first = text[0];
    if (first == 0x43) {
        u8 second = text[1];
        if (second == 0x59) {
            result = 1;
            func_0011D9A8(text + 2, (const char *)D_002218B8, out1);
        } else if (second == 0x52) {
            result = 4;
            func_0011D9A8(text + 2, (const char *)D_002218B8, out1);
        } else if (second == first) {
            result = 2;
            func_0011D9A8(text + 2, (const char *)D_002218C0, out1, out2);
        }
    } else if (first == 0x48) {
        result = 6;
        func_0011D9A8(text + 2, (const char *)D_002218B8, out1);
    }
    return result;
}
