#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_0015F2F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_00172160[];

typedef struct {
    char name[16];
} E16;

typedef struct {
    char name[4];
    u8 term;
    u8 pad[3];
} E8;

typedef struct {
    E16 ent[10];
    E8 sub[10];
    u8 fF0[10];
    u8 fFA[10];
    u8 tbl[10];
    u8 cur[10];
    u8 pad[0x91];
    u8 f1A9;
} Rec;

Rec *D_0021DFE8 = 0;
s8 *D_0021DFF0 = 0;

/* applies a state update message for one slot, copying its name and data when the slot is idle */
s32 func_0015FE78(s32 a0, s32 a1, s32 a2, u8 *a3) {
    Rec *p;
    u32 t;
    u8 k;

    if (D_00172160[0x250] != 0) {
        p = D_0021DFE8;
        if (p != 0) {
            t = a3[6];
            k = t;
            if (k == 1) {
                if (p->tbl[*(s32 *)a3] != 0xFF && p->tbl[*(s32 *)a3] == a2) {
                    if (p->cur[0] >= 7) {
                        *(s32 *)(D_00172160 + 0x66C + *(s32 *)a3 * 4) = 3;
                        *(s32 *)(D_00172160 + 0x644 + *(s32 *)a3 * 4) = a2;
                    } else {
                        *(s32 *)(D_00172160 + 0x644 + *(s32 *)a3 * 4) = a2;
                        *(s32 *)(D_00172160 + 0x66C + *(s32 *)a3 * 4) = 2;
                        p->cur[*(s32 *)a3] = 0;
                    }
                }
            } else {
                if (p->tbl[*(s32 *)a3] != 0xFF && p->tbl[*(s32 *)a3] == a2) {
                    if (p->cur[0] >= 7) {
                        if (k >= 7) {
                            p->cur[*(s32 *)a3] = t;
                        }
                    } else {
                        if (k != 6) {
                            func_0011AFC8(p->ent[*(s32 *)a3].name, (char *)(a3 + 7), 0x10);
                            D_0021DFE8->ent[*(s32 *)a3].name[15] = 0;
                            func_0011AFC8(D_0021DFE8->sub[*(s32 *)a3].name, (char *)(a3 + 0x17), 4);
                            D_0021DFE8->sub[*(s32 *)a3].term = 0;
                            D_0021DFE8->fFA[*(s32 *)a3] = func_0015F2F8(D_0021DFE8->f1A9, D_0021DFF0[0x22] != 0, a3[4], *(s32 *)a3);
                            D_0021DFE8->fF0[*(s32 *)a3] = a3[5];
                        }
                        D_0021DFE8->cur[*(s32 *)a3] = a3[6];
                    }
                }
            }
        }
    } else {
        *(s32 *)(D_00172160 + 0x694) = 1;
        *(s32 *)(D_00172160 + 0x698) = a3[6];
        *(s32 *)(D_00172160 + 0x69C) = *(s32 *)a3;
    }
    return 0x20;
}
