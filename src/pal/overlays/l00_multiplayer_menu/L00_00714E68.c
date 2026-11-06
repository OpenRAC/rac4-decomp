#include "common.h"

void *func_L00_006A1198(s32);                       

s32 func_L00_00714E68(void *arg0, s32 arg1) {
    return (s32) ((*(f32 *)((s8 *)(func_L00_006A1198(arg1 | (*(s32 *)((s8 *)(arg0) + (0x10))))) + (0x1C))) * 512.0f);
}
