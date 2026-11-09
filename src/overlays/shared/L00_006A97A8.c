#include "common.h"
typedef struct Type1 { u8 pad0[0xBC]; s16 fBC; u8 pad1[0x100 - 0xBE]; } Type1;
extern Type1 *D_00222454;
extern Type1 *D_00222470;
extern s32 D_002446C0[];
extern s32 D_00244740[];
extern s32 D_002447C0[];
extern s32 D_00244840[];
void func_L00_006A97A8(void) {
    s32 i;
    Type1 *entry;
    s32 n1;
    s32 n2;
    for (i = 0x1F; i >= 0; i--) {
        D_002446C0[i] = 0;
    }
    for (i = 0x1F; i >= 0; i--) {
        D_00244740[i] = 0;
    }
    for (i = 0x1F; i >= 0; i--) {
        D_002447C0[i] = 0;
    }
    for (i = 0x1F; i >= 0; i--) {
        D_00244840[i] = 0;
    }
    entry = D_00222454;
    n1 = 0;
    n2 = 0;
    for (; entry < D_00222470; entry++) {
        if (entry->fBC == 0x19C4) {
            D_002446C0[n1++] = (s32)entry;
        } else if (entry->fBC == 0x2F6) {
            D_00244740[n2++] = (s32)entry;
        }
    }
}
