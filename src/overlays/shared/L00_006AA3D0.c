#include "common.h"

extern u8 *D_00343EA0[];
typedef void (*Type1)(void *);

void func_L00_006AA3D0(void) {
    s32 i = 0;
    do {
        u8 *node = D_00343EA0[i];
        if (node != 0) {
            do {
                u8 *cur = node;
                node = *(u8 **)(node + 0xC);
                (*(Type1 *)(*(u8 **)(cur + 0x14) + 0xC))(cur);
            } while (node != 0);
        }
        i++;
    } while (i < 7);
}
