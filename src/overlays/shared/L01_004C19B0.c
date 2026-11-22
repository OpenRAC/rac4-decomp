#include "common.h"
typedef struct O { char _p[0x68]; u8 f68; } O;
extern void func_L01_005ABD28(void *, f32, f32);
extern void func_L01_005ABDE8(void *, f32, f32, f32);
extern void func_00473A88(void *, u8, s32);
s32 func_L01_004C19B0(O *obj, s32 sel) {
    switch (sel) {
 case 0: func_L01_005ABD28(obj, 0.06666667f, 0.13333334f); break;
 case 1: func_L01_005ABDE8(obj, 10.0f, 20.0f, 32.0f); break;
 case 4: func_00473A88(obj, obj->f68, -1); break;
 }
 return 1;
}
