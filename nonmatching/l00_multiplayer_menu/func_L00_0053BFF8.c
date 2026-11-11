/* Not matching yet: BYTES 7/616 (tools/try_func.py func_L00_0053BFF8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    char _p0[0xC];
    u16 fC;
} Type2;

typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    s32 f10;
    char _p14[0x20 - 0x14];
    Type2 *f20;
} Type1;

typedef struct Type3 {
    char *f0;
    char *f4;
} Type3;

extern void *func_0011C920(char *arg0, char *arg1);
extern s32 func_0011CB08(Type2 *arg0, s32 arg1, s32 arg2);
extern s32 func_0011CF18(Type2 *arg0);
extern s32 func_0011C2D8(Type2 *arg0);
extern s32 *func_0011A1A0(void);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void func_L00_0051A148(s32, char *, char *, char *, char *, char *);
extern void func_L00_0053BF08(Type1 *arg0);

s64 func_L00_0053BFF8(Type1 *arg0, s32 arg1, s32 arg2, Type3 *arg3) {
    char mode[16];
    Type3 args;
    s64 r = 1;
    Type2 *fp = arg0->f20;

    switch (arg1) {
    case 1:
    case 128:
        if (func_0011CB08(fp, arg2, 0) != 0) {
            r = -1;
        }
        break;
    case 2:
        { u64 t = fp->fC; r = (t >> 5) & 1; }
        break;
    case 3:
    case 133:
        r = func_0011CF18(fp);
        break;
    case 106:
        func_L00_0053BF08(arg0);
        arg0->f10 = arg2 & 1;
        arg0->f20 = (Type2 *)arg3;
        arg0->fC = 1;
        break;
    case 108:
        if (arg2 & 8) {
            if (arg2 & 2) {
                strcpy(mode, "a+");
            } else {
                strcpy(mode, "a");
            }
        } else if ((arg2 & 6) == 6) {
            strcpy(mode, "r+");
        } else if (arg2 & 4) {
            strcpy(mode, "w");
        } else if (arg2 & 2) {
            strcpy(mode, "r");
        } else {
            func_L00_004F84C8(0x20, 0x6E, 0x64, 0, 0);
            r = 0;
            break;
        }
        args.f0 = (char *)arg3;
        args.f4 = mode;
        goto open;
    case 136:
        args.f0 = arg3->f0;
        args.f4 = arg3->f4;
    open:
        func_L00_0053BF08(arg0);
        arg0->f10 = arg2 & 1;
        fp = func_0011C920(args.f0, args.f4);
        if (fp == NULL) {
            r = 0;
            func_L00_004F84C8(2, 1, *func_0011A1A0(), 0, 0);
            func_L00_0051A148(5, "fopen('", args.f0, "','", args.f4, "')");
            func_L00_004F84C8(0x20, 0x6E, 0x802, 0, 0);
        } else {
            arg0->f20 = fp;
            arg0->fC = 1;
        }
        break;
    case 107:
        if (arg3 != NULL) {
            *(Type2 **)arg3 = fp;
        }
        break;
    case 8:
        r = arg0->f10;
        break;
    case 9:
        arg0->f10 = arg2 & 1;
        break;
    case 11:
        if (func_0011C2D8(arg0->f20) != 0) {
            r = -1;
        }
        break;
    case 12:
        r = 1;
        break;
    case 4:
    default:
        r = 0;
        break;
    }
    return r;
}
