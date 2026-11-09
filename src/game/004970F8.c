/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    s32 unk10;
    u8 pad14[0xC];
    f32 unk20;
    f32 unk24;
    u8 pad28[0x2C];
} Type1;

extern void func_00453608(void *p, s32 v, s32 n);
extern void *func_00497048(void);
extern void func_00497EB8(s32 arg0, s32 arg1);
extern void func_00498890(void);
extern void func_00498D18(void);
extern void func_004998F8(void);
extern void func_0049A218(void);
extern void func_0049AA88(void);
extern void func_0049B688(void);
extern void func_0049B748(void);
extern void func_00501498(void *arg0);
extern void func_00505C90(void *arg0);

extern s32 *D_0021DDA4;
extern s32 D_0021DE10;
extern s32 D_0021EDC4;
extern s32 D_0021EDD4;
extern u8 D_0021EE18;
extern Type1 D_002F32B8[];

void func_004970F8(s32 arg0) {
    Type1 *p = D_002F32B8;
    s32 i;
    s32 j;
    s32 n;

    func_00453608(p, 0, 0x150);
    func_004998F8();
    func_00498890();
    func_00498D18();
    for (j = 0; j < 4; j++, p++) {
        n = *D_0021DDA4;
        if (j >= n) {
            p->unkC = -1;
            p->unk10 = 0;
            p->unk20 = 0;
            p->unk24 = 0;
            continue;
        }
        switch (D_0021EDD4) {
        case 0:
            if (n == 1 || D_0021DE10 <= 0) {
                p->unkC = 0;
                p->unk10 = 0;
                p->unk20 = 0;
                p->unk24 = 0;
            } else {
                p->unkC = 1;
                p->unk10 = 0;
                p->unk20 = 0;
                if (j == 1) {
                    p->unk24 = 0.5f;
                } else {
                    p->unk24 = 0;
                }
            }
            break;
        case 1:
            switch (n) {
            case 1:
                p->unkC = 2;
                p->unk10 = 0x3C;
                p->unk20 = 0;
                p->unk24 = 0;
                break;
            case 2:
                p->unkC = 3;
                p->unk10 = 0x5A;
                p->unk20 = 0;
                if (j == 1) {
                    p->unk24 = 0.5f;
                } else {
                    p->unk24 = 0;
                }
                break;
            case 3:
            case 4:
                p->unkC = 4;
                p->unk10 = 0x78;
                if (j & 1) {
                    p->unk20 = 0.5f;
                } else {
                    p->unk20 = 0;
                }
                if (j & 2) {
                    p->unk24 = 0.5f;
                } else {
                    p->unk24 = 0;
                }
                break;
            }
            break;
        }
    }
    func_0049AA88();
    if (D_0021EE18 == 0) {
        func_0049A218();
    }
    func_0049B688();
    if (arg0 != 0) {
        func_0049B748();
        func_00501498(func_00497048());
        func_00505C90(func_00497048());
    }
    if (D_0021EE18 != 0) {
        func_00497EB8(0, 2);
        return;
    }
    if (D_0021EDD4 == 0) {
        for (i = 0; i < *D_0021DDA4; i++) {
            func_00497EB8(i, 0);
        }
    } else if (D_0021DE10 == 0 || D_0021EDC4 == 10) {
        for (i = 0; i < *D_0021DDA4; i++) {
            func_00497EB8(i, 0);
        }
    } else {
        for (i = 0; i < *D_0021DDA4; i++) {
            func_00497EB8(i, 0);
        }
    }
}
