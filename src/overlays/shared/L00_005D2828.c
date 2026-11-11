#include "common.h"

typedef struct {
    u8 pad[0x18];
    s32 f18;
} Type1;

extern s32 D_00222364;
extern Type1 D_00244D00[];
extern void func_L00_005BCBF0(void *, void *, s32);

/* Copies a relocatable block to *dest, fixes up its entry offsets and advances *dest */
void func_L00_005D2828(s32 *arg0, s32 *arg1) {
    s32 size;
    s32 i;

    D_00244D00[0].f18 = arg0[0];
    size = arg0[1];
    size += 3;
    size &= ~3;
    D_00222364 = *arg1;
    func_L00_005BCBF0((void *)D_00222364, arg0 + 2, size);
    for (i = 0; i < D_00244D00[0].f18; i++) {
        *(s32 *)(D_00222364 + i * 16) += D_00222364;
    }
    *arg1 = (*arg1 + size + 0x3F) & 0xFFFFFFC0;
}
