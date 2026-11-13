#include "common.h"

extern void *D_002233A4;

void func_L00_0076ED88(void *arg0) {
    void *t = *(void **)((u8 *)D_002233A4 + 0x48);

    if (*(void (**)(void *))((u8 *)t + 0x424) != 0) {
        (*(void (**)(void *))((u8 *)t + 0x424))(arg0);
    }
    if (*(u8 *)((u8 *)arg0 + 0x8C) != 0) {
        *(u8 *)((u8 *)t + 0) = 0;
    }
}
