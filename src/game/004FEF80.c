#include "common.h"

typedef struct A_004FEF80 {
    s32 unk0;
    u8 pad4[0x8 - 0x4];
    void *unk8;
    s32 unkC;
    s32 unk10;
    struct B_004FEF80 *unk14;
    u8 unk18[0x18];
    u8 unk30[0x18];
    u8 unk48[0x18];
    u8 pad60[0x64 - 0x60];
    s32 unk64;
} A_004FEF80;

typedef struct B_004FEF80 {
    u8 pad0[0x38];
    s32 unk38;
} B_004FEF80;

extern u8 D_003D3548[];
extern void func_00453608(void *, s32, s32);
extern u8 *func_004FEE70(A_004FEF80 *, u8 *);
extern s32 func_00501598(A_004FEF80 *);
extern s32 func_00502440(u8 *);
extern u8 *func_00502848(s32, s32);

A_004FEF80 *func_004FEF80(A_004FEF80 *arg0, s32 arg1, B_004FEF80 *arg2) {
    s32 id;
    u8 *data;
    u8 *p;
    s32 n;
    s32 i;

    func_00501598(arg0);
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk64 = 0;
    arg0->unk14 = arg2;
    arg0->unk8 = D_003D3548;
    func_00453608(arg0->unk18, 0, 0x18);
    func_00453608(arg0->unk30, 0xFF, 0x18);
    func_00453608(arg0->unk48, 0, 0x18);
    id = arg2->unk38;
    if (arg2 != NULL && id >= 0 && (data = func_00502848(arg1, id)) != NULL) {
        i = 0;
        p = data;
        n = func_00502440(p);
        p += 4;
        for (; p != NULL && i < n; i++) {
            p = func_004FEE70(arg0, p);
        }
        arg0->unk0 = 1;
    } else {
        arg0->unk14 = NULL;
        arg0->unk0 = 0;
    }
    return arg0;
}
