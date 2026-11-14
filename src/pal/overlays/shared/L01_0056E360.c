#include "common.h"

typedef struct Type2 Type2;

void func_L01_0056E360(u8 *arg0, Type2 *arg1) {
    s32 i;
    s32 found;
    s32 bits;
    s32 shift;

    if (arg0 != NULL && arg1 != NULL) {
        if (*(s32 *)((u8 *)arg1 + 4) != -1) {
            *(s32 *)(arg0 + 0x178) |= 1 << *(u8 *)((u8 *)arg1 + 3);
        } else {
            found = 0;
            for (i = 0; found == 0 && i < *(u8 *)((u8 *)arg1 + 2); i++) {
                bits = *(s32 *)(arg0 + 0x178);
                shift = *(u8 *)((u8 *)arg1 + 3) + i;
                if (((bits >> shift) ^ 1) & 1) {
                    found = 1;
                    *(s32 *)(arg0 + 0x178) = bits | (1 << shift);
                }
            }
        }
    }
}
