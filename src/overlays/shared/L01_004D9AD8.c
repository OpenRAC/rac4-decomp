#include "common.h"

const char *func_0045E038(s32 id);
void func_00473A88(void *object, s32 state, s32 animation);
void func_L01_005D74F0(s32 a0, s32 a1, s32 a2);

s32 func_004534D0(void *);
extern s32 D_0021EBDC;

void func_L01_004D9AD8(void *arg0) {
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x20)));
    temp_s1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    switch (temp_v1) {
    case 0:
        (*(s32 *)((s8 *)(temp_s1) + (4))) = (s32) ((f32) (*(s32 *)((s8 *)(temp_s1) + (0))) * 60.0f);
        func_00473A88(arg0, 1, -1);
        return;
    case 1:
        if (D_0021EBDC != 0) {
            func_00473A88(arg0, 2, -1);
            return;
        }
        if (func_004534D0(temp_s1 + 4) != 0) {
            D_0021EBDC = 2;
            func_00473A88(arg0, 2, -1);
        }
        func_L01_005D74F0(0, (s32)func_0045E038(0x255D), (*(s32 *)((s8 *)(temp_s1) + (4))));
        return;
    }
}
