#include "common.h"

void func_L00_005C28D8(void *a0, void *a1);
extern u8 D_004C5A10[];
extern void func_L00_005C28D8(void *, void *);
extern void func_0011AFC8(void *, s32, s32);

/* PAL: from rac3-decomp's func_L39_005958A0 */
void func_L00_005C2988(s32 a0, s32 a1, s32 a2) {
    s32 off;
    off = a2;
    func_0011AFC8(D_004C5A10, a1, a2);
    D_004C5A10[off] = 0;
    func_L00_005C28D8(D_004C5A10, a0);
}
