#include "common.h"

void func_L00_005C16A8(void *a0, void *a1);
extern u8 D_004C50D0[];
extern void func_L00_005C16A8(void *, void *);
extern void func_0011AFC8(void *, s32, s32);

/* from rac3-decomp's func_L39_005958A0 */
void func_L00_005C1758(s32 a0, s32 a1, s32 a2) {
    s32 off;
    off = a2;
    func_0011AFC8(D_004C50D0, a1, a2);
    D_004C50D0[off] = 0;
    func_L00_005C16A8(D_004C50D0, a0);
}
