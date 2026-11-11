#include "common.h"

void func_L00_005C27F0(u8 *src, u8 *dst);
void func_L00_005C26B8(u8 *src, u8 *dst);
extern void func_L00_005C27F0(u8 *, u8 *);
extern void func_L00_005C26B8(u8 *, u8 *);
extern void func_0011A518(void *, s32, s32);
extern void func_L00_005C28D8(void *, void *);

/* PAL: from rac3-decomp's func_L39_005957F0, constants adapted */
void func_L00_005C28D8(void *a0, void *a1) {
    u8 local[0x1000];
    func_0011A518(local, 0, 0x1000);
    func_L00_005C27F0(a0, local);
    func_L00_005C26B8(local, a1);
}
