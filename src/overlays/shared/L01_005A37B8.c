#include "common.h"
extern u8 *func_005A3780(const u8 *);
extern void *func_00476F50(void *);
extern s32 func_L01_005A4680(void *);
extern s32 func_L01_005A4648(const u8 *);
void func_L01_005A37B8(void *object,s32 mode,s32 enable)
{
    u8 *state=func_005A3780(object);
    void *value=func_00476F50(object);
    if(state){
        *(s16 *)(state+8)=mode;
        *(void **)state=value;
        if(enable)func_L01_005A4680(object);
        else func_L01_005A4648(object);
    }
}
