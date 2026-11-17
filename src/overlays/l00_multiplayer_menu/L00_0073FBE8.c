#include "common.h"

extern s32 func_L00_0073FB98(s32);

s32 D_002211A4 = 0;
u8 D_002211A8 = 0;
s32 D_002211B0 = 0;
s32 D_002211B4 = 0;
s32 D_002211B8 = 0;

/* Find the column of a character code in the current text, or 0x20. */
s32 func_L00_0073FBE8(s16 ch) {
    s32 found;
    s32 i;
    s32 n;
    s32 pos;
    s32 k;
    s32 c;
    s32 none = -1;
    if (D_002211A8 == 0) {
        return ch & 0xFF;
    }
    found = none;
    n = D_002211B8;
    if (D_002211A4 < n) n = D_002211A4;
    pos = D_002211B0;
    for (i = 0; found < 0 && i < n; i++) {
        if (i == ch - 0x20) found = ch;
    }
    k = n;
    if (found < 0 && k < D_002211A4) {
        do {
            c = func_L00_0073FB98(k);
            if (c >= 0x80) {
                switch (pos & 0xFF) {
                case 0:
                case 0x25:
                case 0x5C:
                    pos++;
                }
                if (c == ch) found = pos + D_002211B4;
                pos++;
            }
            k++;
        } while (found < 0 && k < D_002211A4);
    }
    return found > none ? found : 0x20;
}
