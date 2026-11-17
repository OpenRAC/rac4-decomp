#include "common.h"

extern s32 D_00222614;
extern void *func_L00_005DEBD0(s32, s32, s32);
extern void func_L00_005C9850(s32, s32, s32);

// Run the callbacks of the two linked table entries; a callback that returns non-zero raises message 0x331F.
void func_L06_004C45F8(u8 *object) {
    u8 *linked;
    s32 idx0;
    s32 idx1;
    u8 *s2;
    u8 *s3;
    void *s0;
    void *s1;
    s32 (*fn)(void *);

    linked = *(u8 **)(object + 0xAC);
    idx0 = *(s32 *)linked;
    if (idx0 == -1) {
        return;
    }
    idx1 = *(s32 *)(linked + 4);
    if (idx1 == -1) {
        return;
    }
    s2 = (u8 *)(D_00222614 + (idx0 << 8));
    s3 = (u8 *)(D_00222614 + (idx1 << 8));
    s0 = func_L00_005DEBD0(*(s16 *)(s2 + 0xBC), 0x14, 8);
    s1 = func_L00_005DEBD0(*(s16 *)(s3 + 0xBC), 0x14, 8);
    if ((s0 != 0 && (fn = *(s32 (**)(void *))((u8 *)s0 + 4)) != 0 && fn(s2) != 0) ||
        (s1 != 0 && (fn = *(s32 (**)(void *))((u8 *)s1 + 4)) != 0 && fn(s3) != 0)) {
        func_L00_005C9850(0x331F, 0x76A, 2);
    }
}
