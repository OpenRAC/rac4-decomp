#include "common.h"

extern s32 D_0023AC10[];

/* from rac3-decomp's func_L39_0061C258 */
void func_L13_004FE300(s32 a0) {
    s32 i = 0;
    if (D_0023AC10[0] == 0) {
        D_0023AC10[0] = a0;
        return;
    }
loop:
    i++;
    if (i >= 0x10)
        return;
    if (D_0023AC10[i] != 0)
        goto loop;
    D_0023AC10[i] = a0;
}
