#include "common.h"

extern void func_0047C5B8(s32);
extern void func_L01_004967E8(void *arg0);
extern s32 func_L01_0056F988(u8 *object);

/* Sets two halfwords of the object's linked block, then calls three helpers on the object */
void func_L01_00496B28(u8 *arg0) {
    u8 *temp_v1;

    temp_v1 = *(u8 **)(arg0 + 0xAC);
    *(s16 *)(temp_v1 + 0x4D4) = 50;
    *(s16 *)(temp_v1 + 0x4D6) = -1;
    func_0047C5B8((s32)arg0);
    func_L01_0056F988(arg0);
    func_L01_004967E8(arg0);
}
