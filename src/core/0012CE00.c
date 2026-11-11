/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern char D_001932E0[];
extern char D_001932F0[];
extern void func_001294F0();
extern void func_00129D90(s32);
extern void func_00129F30(void);
extern s32 func_0012CC30(const char *arg, s32 mode);

/* from rac2-decomp's func_0011EED8 */
s32 func_0012CE00(char *img) {
    char *prefix = D_001932E0;
    char param[80];
    char *p;
    char *d;

    p = img;
    while (*p) {
        p++;
    }
    if ((u32)(p + 11 - img) > 80) {
        func_001294F0(D_001932F0, img);
        return 0;
    }
    func_00129D90(0);
    func_00129F30();
    d = param;
    while (*prefix) {
        *d++ = *prefix++;
    }
    while (*img) {
        *d++ = *img++;
    }
    *d = 0;
    return func_0012CC30(param, 0);
}
