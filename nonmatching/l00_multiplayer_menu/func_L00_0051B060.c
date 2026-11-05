/* Not matching yet: BYTES 6/420 (tools/try_func.py func_L00_0051B060 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 f18[0x40];
};

void func_0011A370(void *, void *, s32);
void func_0011A518(void *, s32, s32);
s32 func_00540E58(s32);
s32 func_L00_00519490(s32, s32);
void func_L00_00519578(s32, void *, s32);
void func_L00_005195A8(s32, void *, void *);
s32 func_L00_00540F30(s32, s32);

s32 func_L00_0051B060(Type1 *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 buf[0x40];
    s32 i;
    s32 flag;

    flag = 0;
    if (arg3 != 0) {
        flag = 1;
        arg0->f0 = arg3;
    } else {
        arg3 = arg0->f0;
    }
    if (arg1 != 0) {
        flag = 1;
        if (func_00540E58(arg3) < arg2) {
            if (func_L00_00519490(arg0->f4, arg3) == 0) {
                return 0;
            }
            func_L00_00519578(arg0->f4, arg1, arg2);
            func_L00_005195A8(arg0->f4, arg0->f18, &arg0->f14);
        } else {
            func_0011A370(arg0->f18, arg1, arg2);
            func_0011A518(arg0->f18 + arg2, 0, 0x40 - arg2);
            arg0->f14 = arg2;
        }
    }
    if (flag != 0) {
        for (i = 0; i < 0x40; i++) {
            buf[i] = arg0->f18[i] ^ 0x36;
        }
        if (func_L00_00519490(arg0->f8, arg3) == 0) {
            return 0;
        }
        func_L00_00519578(arg0->f8, buf, func_00540E58(arg3));
        for (i = 0; i < 0x40; i++) {
            buf[i] = arg0->f18[i] ^ 0x5C;
        }
        func_L00_00519490(arg0->fC, arg3);
        func_L00_00519578(arg0->fC, buf, func_00540E58(arg3));
    }
    return func_L00_00540F30(arg0->f4, arg0->f8) != 0;
}
