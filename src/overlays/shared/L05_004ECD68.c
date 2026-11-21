#include "common.h"

typedef struct {
    u8 pad0[0xAC];
    u8 *fAC;
    u8 padB0[0xBC - 0xB0];
    s16 fBC;
    u8 padBE[0x100 - 0xBE];
} Type1;
typedef struct {
    s32 f0[4];
    s32 f10[4];
    s32 f20[4];
} Type2;
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 func_L05_004DBBB0(Type1 *);
extern Type1 *D_222B14;
extern s32 D_0021DDB8;

/* For state 0, clear the flag of each linked row and hand the object to state 1; for state 1, mark the matching rows. */
void func_L05_004ECD68(u8 *arg0) {
    Type2 *rows;
    u8 *o;
    s32 i;

    rows = *(Type2 **)(arg0 + 0xAC);
    switch (arg0[0x20]) {
    case 0:
        arg0[0x30] = 0xFF;
        if (D_0021DDB8 < 0xF) {
            return;
        }
        for (i = 0; i < 4; i++) {
            if (rows->f0[i] != -1 && rows->f10[i] != -1 && rows->f20[i] != -1) {
                if (D_222B14[rows->f0[i]].fBC == 0x2075) {
                    o = D_222B14[rows->f0[i]].fAC;
                    if (o != NULL) {
                        o = *(u8 **)(o + 0xC);
                        if (o != NULL) {
                            o = *(u8 **)(o + 0xAC);
                            if (o != NULL) {
                                *(u16 *)(o + 0x58) = 0;
                            }
                        }
                    }
                }
            }
        }
        func_L01_00591BD8(arg0, 1, -1);
        return;
    case 1:
        for (i = 0; i < 4; i++) {
            if (rows->f0[i] != -1 && rows->f10[i] != -1 && rows->f20[i] != -1
                && D_222B14[rows->f0[i]].fBC == 0x2075 && func_L05_004DBBB0(&D_222B14[rows->f20[i]]) != 0) {
                o = D_222B14[rows->f0[i]].fAC;
                if (o != NULL) {
                    o = *(u8 **)(o + 0xC);
                    if (o != NULL) {
                        o = *(u8 **)(o + 0xAC);
                        if (o != NULL) {
                            *(u16 *)(o + 0x58) = 10;
                        }
                    }
                }
            }
        }
        break;
    }
}
