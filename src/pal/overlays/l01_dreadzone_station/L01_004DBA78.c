#include "common.h"

const char *func_0045E850(s32 id);
void func_00474368(void *object, s32 state, s32 animation);
void func_L01_005DBFA0(s32 a0, s32 a1, s32 a2);

s32 func_00453CE8(void *);                             /* extern */
extern s32 D_0021EC5C;

void func_L01_004DBA78(void *arg0) {
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x20)));
    temp_s1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    switch (temp_v1) {                              /* irregular */
    case 0:
        (*(s32 *)((s8 *)(temp_s1) + (4))) = (s32) ((f32) (*(s32 *)((s8 *)(temp_s1) + (0))) * 50.0f);
        func_00474368(arg0, 1, -1);
        return;
    case 1:
        if (D_0021EC5C != 0) {
            func_00474368(arg0, 2, -1);
            return;
        }
        if (func_00453CE8(temp_s1 + 4) != 0) {
            *(s32 *)0x21EC5C = 2;
            func_00474368(arg0, 2, -1);
        }
        func_L01_005DBFA0(0, (s32)func_0045E850(0x255D), (*(s32 *)((s8 *)(temp_s1) + (4))));
        return;
    }
}
