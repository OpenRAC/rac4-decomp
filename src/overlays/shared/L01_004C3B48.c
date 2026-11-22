#include "common.h"
extern void func_L01_005ABD28(void *, f32, f32);
extern void func_L01_005ABDE8(void *, f32, f32, f32);
s32 func_L01_004C3B48(void *obj, s32 sel) {
    switch (sel) {
 case 0: func_L01_005ABD28(obj, -0.050000004f, 0.016666668f); break;
 case 1: func_L01_005ABDE8(obj, 0.0f, 3.0f, 14.0f); break;
 case 2: break;
 }
 return 1;
}
