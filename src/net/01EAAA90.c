/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_00168B84;
extern s32 *D_00168B8C;
extern s32 D_00168B90;
extern u32 D_001B23BC;
extern u32 D_001B23C0;
s32 func_01EAAA90(u32 i, u32 j, s32 *out) {
    if (out == 0) {
        return 2;
    }
    *out = 0;
    if (D_00168B84 != 1) {
        return 5;
    }
    if (D_00168B8C == 0) {
        return 5;
    }
    if (D_00168B90 == 0) {
        return 5;
    }
    if (i >= D_001B23C0) {
        return 2;
    }
    if (j >= D_001B23BC) {
        return 2;
    }
    *out = D_00168B8C[i * D_001B23BC + j];
    return *out != 0 ? 0 : 2;
}
