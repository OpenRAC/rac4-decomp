#include "common.h"

extern u8 *D_0021DF68;
extern void func_L00_0071A080(void);

void func_L00_00719FD8(u8 *arg0) {
    if (D_0021DF68 == NULL) {
        func_L00_0071A080();
        arg0[0x5E] = 0;
    }
}
