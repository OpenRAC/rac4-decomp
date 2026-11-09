#include "common.h"

typedef struct S_arg0 S_arg0;
struct S_arg0 {
    char _p0[0x6A];
    u16 f6A;
    char _p6C[0x40];
    u8 *fAC;
};

s32 func_L00_005FC990(void *);
s32 func_L01_004E3748();
void func_L01_0059B5C0(f32, f32, void *, void *, s32);

void func_L01_004E3418(S_arg0 *arg0) {
    u8 *temp_s1;
    u16 temp_v1;

    temp_s1 = arg0->fAC;
    if (func_L01_004E3748() == 0) {
        temp_v1 = arg0->f6A;
        if (temp_v1 <= 0xFFFEU) {
            arg0->f6A = (u16) (temp_v1 + 1);
        }
        func_L01_0059B5C0(0.03f, 0.3f, arg0, temp_s1 + 0x4A0, 2);
        func_L00_005FC990(arg0);
    }
}
