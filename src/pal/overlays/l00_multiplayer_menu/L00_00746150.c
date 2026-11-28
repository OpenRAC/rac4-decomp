#include "common.h"

extern s32 func_0011AB04(const char *text);

/* Trim trailing spaces from the text at +0x284, preserving a space after 0x80. */
char *func_L00_00746150(u8 *object) {
    u8 *text;
    s32 index;

    text = object + 0x284;
    index = func_0011AB04((const char *)text) - 1;
    while (index > 0 && text[index] == ' ' && text[index - 1] != 0x80) {
        index -= 1;
    }
    text[index + 1] = 0;
    return (char *)text;
}
