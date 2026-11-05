/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type2;

typedef struct Type1 {
    char _p0[0xD8];
    Type2 *fD8;
} Type1;

extern void func_L00_005206A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);
extern void func_L00_005535D0(Type2 *arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4, s32 arg5, s32 arg6);

s32 func_L00_00551E18(Type1 *arg0, s32 arg1, s64 *arg2, s64 arg3, s64 arg4, s64 arg5) {
    Type2 *rec;

    if (arg3 < 0x20) {
        if (func_L00_005208E8(arg1, arg4, arg5, 0, &rec, 0) != 0) {
            return 1;
        }
        func_L00_005535D0(arg0->fD8, 0, arg3, rec->fC, rec->f10, 0, 0);
    } else if (arg3 == 0x41) {
        if (func_L00_005208E8(arg1, arg4, arg5, 0, &rec, 0) != 0) {
            return 1;
        }
        func_L00_005535D0(arg0->fD8, 0, rec->f8, rec->fC, rec->f10, 0, 0);
    } else if (arg3 == 0x44) {
        if (func_L00_005208E8(arg1, arg4, arg5, 0, &rec, 0) != 0) {
            return 1;
        }
        *arg2 = rec->f10;
    } else if (arg3 == 0x42) {
        func_L00_005206A8(arg1, arg4, arg5, arg0->fD8->f10, arg0->fD8->f8, arg0->fD8->f0, 0x10);
    } else if (arg3 == 0x43) {
        func_L00_005206A8(arg1, arg4, arg5, 2, 0, *arg2, 0x10);
    } else if (arg3 == 0x40) {
        func_L00_005208E8(arg1, arg4, arg5, 0, &rec, 0);
        *arg2 = rec != 0;
        return 0;
    } else {
        return 2;
    }
    return 0;
}
