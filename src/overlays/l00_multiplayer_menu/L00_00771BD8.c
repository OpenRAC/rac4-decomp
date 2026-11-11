#include "common.h"

s32 func_0012E370(void);
long func_0012FEB0(s32, long);
void func_L00_00771C70(void *, s32, s32, s32);
extern s32 func_0012E370(void);
extern long func_0012FEB0(s32, long);

/* from rac3-decomp's func_L39_006D66B8 */
s32 func_L00_00771BD8(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;
    temp_s1 = 1;
    if (*(u8 *)arg0 != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x8) != 0) {
            s32 temp_a0;
            temp_a0 = func_0012E370();
            temp_v0 = (s32) func_0012FEB0(temp_a0, 0x24000);
            if ((temp_v0 - *(s32 *)((u8 *)arg0 + 0xC)) >= 0x3A99) {
                *(u8 *)((u8 *)arg0 + 0x8) = 0;
                temp_s1 = 0;
                func_L00_00771C70(arg0, *(s32 *)((u8 *)arg0 + 0x5C), *(s32 *)((u8 *)arg0 + 0x60), 1);
            }
        }
    }
    return temp_s1;
}
