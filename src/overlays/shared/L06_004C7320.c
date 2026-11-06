#include "common.h"
s32 func_L06_004C7378();                        /* extern */
s32 func_L06_004C7958(void *);                  /* extern */
s32 func_L06_004C7AD0(void *);                      /* extern */
s32 func_L06_004C7D28(void *);                  /* extern */

void func_L06_004C7320(void *arg0) {
    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0) {
        func_L06_004C7378();
    }
    func_L06_004C7958(arg0);
    if (func_L06_004C7AD0(arg0) != 0) {
        func_L06_004C7D28(arg0);
    }
}
