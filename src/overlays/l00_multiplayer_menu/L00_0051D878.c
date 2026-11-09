/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011AE00(char *, char *, s32);
extern s32 func_0051A700(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_0051A450(s32, s32, s32, void *);
extern void func_L00_0051A668(s32);
extern s32 func_L00_0051A950(char *);
extern s32 func_L00_0051DAB8(char **, void *, s32);
extern char D_004AE2A8[];
extern char D_004AE2B8[];
extern char D_004AE2C8[];

s32 func_L00_0051D878(char *arg0, s32 arg1) {
    char buf[0x20];
    s32 obj;
    char c;
    char *start;

    func_L00_0051A668(arg1);
    if (arg0 == 0) return 1;
    if (*arg0 == 0 || *arg0 == '\n') return 1;
    if (func_0011AE00(arg0, D_004AE2A8, 11) != 0) {
        func_L00_004F84C8(9, 0x76, 0x6B, 0, 0);
        return 0;
    }
    arg0 += 11;
    if (*arg0 != '4') return 0;
    arg0++;
    if (*arg0 != ',') return 0;
    arg0++;
    if (func_0011AE00(arg0, D_004AE2B8, 9) != 0) {
        func_L00_004F84C8(9, 0x76, 0x6A, 0, 0);
        return 0;
    }
    for (; *arg0 != '\n' && *arg0 != 0; arg0++) {
    }
    if (*arg0 == 0) {
        func_L00_004F84C8(9, 0x76, 0x70, 0, 0);
        return 0;
    }
    arg0++;
    if (func_0011AE00(arg0, D_004AE2C8, 10) != 0) {
        func_L00_004F84C8(9, 0x76, 0x69, 0, 0);
        return 0;
    }
    arg0 += 10;
    start = arg0;
    c = *arg0;
    while ((c >= 'A' && c <= 'Z') || c == '-' || (c >= '0' && c <= '9')) {
        arg0++;
        c = *arg0;
    }
    *arg0 = 0;
    obj = func_L00_0051A950(start);
    *arg0 = c;
    arg0++;
    if (obj == 0) {
        func_L00_004F84C8(9, 0x76, 0x72, 0, 0);
        return 0;
    }
    if (func_L00_0051DAB8(&arg0, buf, func_0051A700(obj)) == 0) return 0;
    return func_L00_0051A450(arg1, obj, 0, buf);
}
