#include "common.h"

extern void func_00512D50(void *, unsigned char, int, int, int);
extern s32 func_0051B130(void *arg0, f32 fparg0);

void func_00512DC0(void *arg0) {
    unsigned char *o = arg0;
    unsigned char s;

    if (*(s32 *)(o + 0x25D4) != 1) {
        return;
    }
    if (*(s32 *)(o + 0x25CC) == 2 && *(s32 *)(o + 0x370) < 15) {
        return;
    }
    s = o[0x43B];
    if (*(s32 *)(o + 0x25CC) == 2 && *(s32 *)(o + 0x370) == 0x16) {
        func_00512D50(o, s, 0, 1, 0x1E);
    }
    switch ((*(unsigned char **)(o + 0x2EF0))[0x54]) {
    case 5:
    case 6:
        if (func_0051B130(o, 38.5f)) {
            func_00512D50(o, s, 0, 1, 0x1E);
        }
        if (func_0051B130(o, 12.0f)) {
            func_00512D50(o, s, 1, 1, 0x1E);
        }
        break;
    case 7:
    case 86:
    case 92:
    case 94:
    case 96:
        if (func_0051B130(o, 12.0f)) {
            func_00512D50(o, s, 0, 1, 0x1E);
        }
        if (func_0051B130(o, 1.0f)) {
            func_00512D50(o, s, 1, 1, 0x1E);
        }
        break;
    case 8:
    case 91:
    case 93:
    case 95:
    case 97:
        if (func_0051B130(o, 8.0f)) {
            func_00512D50(o, s, 0, 1, 0x1E);
        }
        if (func_0051B130(o, 21.0f)) {
            func_00512D50(o, s, 1, 1, 0x1E);
        }
        break;
    }
}
