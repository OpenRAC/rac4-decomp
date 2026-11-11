#include "common.h"

extern u8 *D_003468F8[];
typedef void (*Type1)(void *);

void func_L00_006AAE40(void) {
    s32 i = 0;
    do {
        if (i != 0) {
            u8 *node = D_003468F8[i];
            if (node != 0) {
                do {
                    u8 *cur = node;
                    node = *(u8 **)(node + 4);
                    (*(Type1 *)(*(u8 **)(cur + 0xC) + 0x10))(cur);
                } while (node != 0);
            }
        }
        i++;
    } while (i < 7);
}
