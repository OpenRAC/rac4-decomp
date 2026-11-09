/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_L00_0071F2E0();                        /* extern */
s32 func_L00_0071FCE8(void *);                  /* extern */
extern void *D_00220DD4;

void func_L00_0074EFF8(void *arg0) {
    *(u8 *)((u8 *)D_00220DD4 + 0x114) = (u8) *(u8 *)((u8 *)arg0 + 0x260);
    func_L00_0071F2E0();
    func_L00_0071FCE8(arg0);
}