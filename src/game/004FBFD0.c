#include "common.h"

typedef struct {
    s32 w[6];
} Entry;

extern Entry *func_004FBF90(s32, s32);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);
extern s32 D_0021DE10;
extern s32 D_0021F198;
extern u8 D_001F87F0[];

s32 func_004FBFD0(Entry *dst, s32 a, s32 b, s32 force)
{
    s32 count = 0;
    char *info;
    s32 i;

    if (a < 0 || b < 0) {
        a = D_0021DE10;
        b = D_0021F198;
    }
    if (!force && D_001F87F0[b * 12 + ((a - 1) % 20) * 0x304 + 9]) {
        goto out;
    }
    info = func_0054A998(func_0054AB08(a, b));
    for (i = 0; i < 9 && count < 2; i++) {
        if (i == 0 && *(s32 *)(info + 0x24)) {
            dst[count] = *func_004FBF90(0, *(s32 *)(info + 0x24));
            count++;
        } else if (i == 1 && *(u8 *)(info + 0x31)) {
            dst[count] = *func_004FBF90(1, *(u8 *)(info + 0x31));
            count++;
        } else if (i == 5 && *(s32 *)(info + 0x28)) {
            dst[count] = *func_004FBF90(5, *(s32 *)(info + 0x28));
            count++;
        }
    }
out:
    return count;
}
