/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type3 {
    u8 pad0[0x104];
    s32 f104;
    s32 f108;
} Type3;

typedef struct Type1 {
    u8 pad0[0x54];
    char *f54;
    u8 pad58[0xDC - 0x58];
    Type3 *fDC;
    u8 padE0[0x128 - 0xE0];
    s32 f128;
} Type1;

extern s32 func_0011AB04(char *);
extern s32 func_L00_00519490(s32 arg0, s32 arg1);
extern void func_L00_00519578(s32 arg0, char *arg1, s32 arg2);
extern void func_L00_005195A8(s32 arg0, char *arg1, s32 *arg2);
extern char *D_004A1A20[];

s32 func_L00_00528348(Type1 *arg0, char *arg1, char *arg2, s32 arg3) {
    char buf[0x20];
    s32 len;
    s32 i;
    s32 total;
    char **p;

    total = 0;
    i = 0;
    p = D_004A1A20;
    do {
        if (func_L00_00519490(arg0->f128, arg0->fDC->f108) == 0) {
            return 0;
        }
        func_L00_00519578(arg0->f128, *p, func_0011AB04(*p));
        func_L00_00519578(arg0->f128, arg2, arg3);
        func_L00_00519578(arg0->f128, arg0->f54 + 0x64, 0x20);
        func_L00_00519578(arg0->f128, arg0->f54 + 0x44, 0x20);
        func_L00_005195A8(arg0->f128, buf, &len);
        if (func_L00_00519490(arg0->f128, arg0->fDC->f104) == 0) {
            return 0;
        }
        i++;
        func_L00_00519578(arg0->f128, arg2, arg3);
        p++;
        func_L00_00519578(arg0->f128, buf, len);
        func_L00_005195A8(arg0->f128, arg1, &len);
        arg1 += len;
        total += len;
    } while (i < 3);
    return total;
}
