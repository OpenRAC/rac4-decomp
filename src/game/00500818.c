#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 (*f10)(s32, s32);
} Type_00501338;

extern void *func_00501338(Type_00501338 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 (*arg4)(s32, s32));
extern s32 func_00500628(s32, s32);

extern Type_00501338 D_00335D50[];
extern Type_00501338 D_00335D68[];
extern Type_00501338 D_00335D80[];
extern Type_00501338 D_00335D98[];
extern Type_00501338 D_00335DB0[];
extern s32 D_003DD808[];

s32 D_0022201C = 0;
s32 D_00222020 = 0;
s32 D_00222024 = 0;
s32 D_00222028 = 0;
s32 D_0022202C = 0;

s32 func_00500818(s32 arg0) {
    if (D_0022201C == 0) {
        func_00501338(D_00335D50, 0, 0x3FF, 0, func_00500628);
        D_0022201C = 1;
    }
    if (D_00222020 == 0) {
        func_00501338(D_00335D68, 0, 0x3FF, 1, func_00500628);
        D_00222020 = 1;
    }
    if (D_00222024 == 0) {
        func_00501338(D_00335D80, 0, 0x3FF, 2, func_00500628);
        D_00222024 = 1;
    }
    if (D_00222028 == 0) {
        func_00501338(D_00335D98, 0, 0x3FF, 3, func_00500628);
        D_00222028 = 1;
    }
    if (D_0022202C == 0) {
        func_00501338(D_00335DB0, 0, 0x3FF, 4, func_00500628);
        D_0022202C = 1;
    }
    return D_003DD808[arg0];
}
