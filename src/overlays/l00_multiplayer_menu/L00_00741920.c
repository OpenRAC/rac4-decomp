#include "common.h"

s32 func_0011AB04(u8 *);

// Trim trailing spaces of the string at +0x284 of the object (never below one
// character) and return it.
u8 *func_L00_00741920(u8 *object) {
    u8 *text = object + 0x284;
    s32 length = func_0011AB04(text) - 1;
    if (length > 0 && text[length] == 0x20) {
        do {
            length--;
        } while (length > 0 && text[length] == 0x20);
    }
    text[length + 1] = 0;
    return text;
}
