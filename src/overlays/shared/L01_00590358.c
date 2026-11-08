/* cflags: -O2 -G8 */
#include "common.h"

typedef struct Type1 {
    char pad0[0x25CC];
    s32 f25CC;
    s32 pad25D0;
    s32 f25D4;
    char pad25D8[0x26E4 - 0x25D8];
    s32 f26E4;
} Type1;

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 (*f8)(void);
} Type2;

extern Type1 *D_003660F8_[];
extern s32 *D_0021DDA4;
extern Type1 *func_006658C0(s32);
extern Type2 *func_L00_005DEBD0(s32, s32, s32);
extern s32 func_L00_005E60A0(s32);
extern s32 func_L00_006FF6D0(s32, s32);
extern s32 func_L00_006FF700(s32, s32);
extern s32 func_L00_00700708(s32, s32);

static inline s32 func_inl(Type1 *p) {
    return p->f25D4 == 0xF || p->f25CC == 0x27 || p->f25CC == 0x28 || p->f25CC == 0x29 ||
           p->f25CC == 0x2A || p->f25CC == 0x3E || p->f25CC == 0x3F;
}

/* Picks a slot index 2..19 (not 10, 11..14, 16..19) across all entries, at random among eligible ones */
s32 func_L01_00590358(s32 arg0, s32 *arg1) {
    s32 flag;
    s32 i;
    s32 j;
    s32 total;
    s32 under;
    Type2 *obj;
    Type1 *q;

    flag = 0;
    q = D_003660F8_[0];
    for (j = 0; j < 10; j++, q = D_003660F8_[j]) {
        if (q != 0) {
            u8 ok = func_inl(q);
            if (ok && func_L00_006FF6D0(q->f26E4, 2) < func_L00_006FF700(q->f26E4, 2)) {
                flag = 1;
                break;
            }
        }
    }

    under = 0;
    total = 0;
    obj = func_L00_005DEBD0(0x2102, 0x11, 0xC);
    for (i = 0; i < *D_0021DDA4; i++) {
        Type1 *p = func_006658C0(i);
        if (p == 0) continue;
        for (j = 2; j < 20; j++) {
            s32 n;
            if (j == 10) continue;
            if (j > 10 && j != 15) continue;
            if (obj != 0 && obj->f8() && !func_L00_006FF6D0(p->f26E4, j)) continue;
            if (!func_L00_00700708(p->f26E4, j)) continue;
            n = func_L00_006FF700(p->f26E4, j);
            if (n > 0) {
                total++;
                under += func_L00_006FF6D0(p->f26E4, j) < n;
            }
        }
    }

    if (total == 0) {
        return 0;
    }

    if (under != 0) {
        s32 k = func_L00_005E60A0(under);
        for (i = 0; k != -1 && i < *D_0021DDA4; i++) {
            Type1 *p = func_006658C0(i);
            if (p == 0) continue;
            for (j = 2; j < 20; j++) {
                s32 n;
                if (j == 10) continue;
                if (j > 10 && j != 15) continue;
                n = func_L00_006FF700(p->f26E4, j);
                if (obj != 0 && obj->f8() && !func_L00_006FF6D0(p->f26E4, j)) continue;
                if (!func_L00_00700708(p->f26E4, j)) continue;
                if (n <= 0) continue;
                if (func_L00_006FF6D0(p->f26E4, j) >= n) continue;
                if (k == 0) {
                    k = -1;
                    *arg1 = j;
                } else {
                    k--;
                }
            }
        }
    } else {
        s32 k = func_L00_005E60A0(total);
        for (i = 0; k != -1 && i < *D_0021DDA4; i++) {
            Type1 *p = func_006658C0(i);
            if (p == 0) continue;
            for (j = 2; j < 20; j++) {
                s32 n;
                if (j == 10) continue;
                if (j > 10 && j != 15) continue;
                n = func_L00_006FF700(p->f26E4, j);
                if (obj != 0 && obj->f8() && !func_L00_006FF6D0(p->f26E4, j)) continue;
                if (!func_L00_00700708(p->f26E4, j)) continue;
                if (n <= 0) continue;
                if (k == 0) {
                    k = -1;
                    *arg1 = j;
                } else {
                    k--;
                }
            }
        }
    }

    if (flag) {
        *arg1 = 2;
        return 1;
    }
    return 1;
}
