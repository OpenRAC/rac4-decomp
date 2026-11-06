/* cflags: @ee29 */
#include "common.h"

typedef struct S_arg0 S_arg0;
struct S_arg0 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x4];
    s32 fC;
};

extern char D_004AD1F0[];
s32 func_L00_004FAAF0(s32, s32, s32, s32, s32);
s32 func_L00_004FAD28(void *);
s32 func_L00_0051EB68(s32);
s32 func_L00_005205F8(s32);


void func_L00_00519050(S_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;

    if (arg0 != NULL) {
        if (func_L00_004FAAF0((char *)arg0 + 0x10, -1, 0x17, D_004AD1F0, 0x70) <= 0) {
            temp_a0 = arg0->fC;
            if (temp_a0 != 0) {
                func_L00_0051EB68(temp_a0);
            }
            temp_a0_2 = arg0->f4;
            if (temp_a0_2 != 0) {
                func_L00_005205F8(temp_a0_2);
            }
            func_L00_004FAD28(arg0);
        }
    }
}
