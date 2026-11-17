#include "common.h"

typedef struct Type2 {
    u8 pad0[0x274];
    u8 f274;
} Type2;

typedef struct Type1 {
    u8 pad0[0xF8];
    Type2 *f0F8;
} Type1;

extern void func_L00_00719880(void *arg0, s32 arg1, s32 arg2);
extern void func_L00_007629E0(void *arg0);
extern void func_L00_00762A08(void *arg0, s32 arg1);

/* runs the first child's step, then the second child's step when its byte at 0x274 is zero */
void func_L00_00719DF8(Type1 *arg0, s32 arg1, s32 arg2) {
    Type2 *temp_s0;

    temp_s0 = arg0->f0F8;
    if (temp_s0 != NULL) {
        func_L00_007629E0(temp_s0);
        func_L00_00719880(arg0, 0x25, arg2);
        if (temp_s0->f274 == 0) {
            func_L00_00762A08(temp_s0, arg1);
        }
    }
}
