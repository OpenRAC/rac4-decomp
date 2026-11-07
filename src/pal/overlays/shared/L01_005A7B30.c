#include "common.h"
extern u8 *func_L00_005F44F8(const u8 *);
extern void *func_L00_005EDEE8(void *);
extern s32 func_L01_005A89F8(void *);
extern s32 func_L01_005A89C0(const u8 *);
void func_L01_005A7B30(void *object,s32 mode,s32 enable)
{
    u8 *state=func_L00_005F44F8(object);
    void *value=func_L00_005EDEE8(object);
    if(state){
        *(s16 *)(state+8)=mode;
        *(void **)state=value;
        if(enable)func_L01_005A89F8(object);
        else func_L01_005A89C0(object);
    }
}
