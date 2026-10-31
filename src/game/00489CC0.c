#include "common.h"

typedef struct {
    u8 pad[0x48];
    s16 f48;
    s16 f4A;
    s16 f4C;
} Type1;

extern void func_00488F30(s16 a, s16 b, s16 c);
extern Type1 D_206948[];
s32 D_0021F344 = 0;

// Stores arg0 into the record arg1 and updates its state byte at +0xA; when arg0 is 0 and the flag is clear, passes the D_206948 triple to func_00488F30.
void func_00489CC0(s32 arg0, s64 arg1) {
    u8 *arg1p = (u8 *)(s32)arg1;

    if (arg1p != 0) {
        *(s32 *)arg1p = arg0;
        if (arg0 != 0) {
            if (*(s16 *)(arg1p + 0xA) == 1) {
                *(s16 *)(arg1p + 0xA) = 2;
            }
        } else if (D_0021F344 == 0) {
            func_00488F30(D_206948[0].f48, D_206948[0].f4C, D_206948[0].f4A);
        } else {
            *(s16 *)(arg1p + 0xA) = 0;
        }
    }
}
