#include "common.h"

extern void func_L00_005F1520(s32);
extern void func_L01_00494FF0(void *arg0);
extern s32 func_L01_0056CDB0(u8 *object);

/* Sets two halfwords of the object's linked block, then calls three helpers on the object */
void func_L01_00495330(u8 *arg0) {
    u8 *temp_v1;

    temp_v1 = *(u8 **)(arg0 + 0xAC);
    *(s16 *)(temp_v1 + 0x4D4) = 0x3C;
    *(s16 *)(temp_v1 + 0x4D6) = -1;
    func_L00_005F1520((s32)arg0);
    func_L01_0056CDB0(arg0);
    func_L01_00494FF0(arg0);
}
