#include "common.h"

typedef struct {
    u8 pad0[4];
    u16 f4;
    s16 f6;
    u16 f8;
    u8 padA[0x16];
} Type1;

typedef struct {
    u8 pad0[8];
    u16 f8;
    u8 padA[2];
} Type2;

typedef struct {
    u8 pad0[4];
    u16 f4;
    s16 f6;
    u16 f8;
    u8 padA[2];
} Type3;

typedef struct {
    u16 f0;
    u16 f2;
} Type4;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
} Type5;

typedef struct {
    u8 pad0[0x3010];
    Type2 *f3010;
    s32 f3014;
    Type1 *f3018;
    s32 f301C;
    Type5 *f3020;
    u8 pad3024[0xC];
    Type3 *f3030;
    s32 f3034;
    Type4 *f3038;
} Type6;

extern Type6 *D_002214D8;

void func_0048D228(u16 arg0, u16 arg1, s32 arg2, u16 *arg3, u16 *arg4, s32 *arg5);
void func_0048D330(u16 arg0, u16 arg1, s32 arg2, u16 *arg3, u16 *arg4, s32 *arg5);

/* recursive search for the cheapest route between two nodes */
void func_0048D758(u16 arg0, u16 arg1, s32 arg2, u16 *arg3, u16 *arg4, s32 *arg5) {
    u16 a0;
    u16 a1;
    u16 b0;
    u16 b1;
    u16 c0;
    u16 c1;
    s32 aCost;
    s32 bCost;
    s32 cCost;
    Type1 *n0;
    Type1 *n1;
    Type2 *e0;
    Type2 *e1;
    Type3 *area;
    Type4 *it;
    Type4 *end;
    Type1 *node;
    Type5 *e;
    Type5 *eend;
    s32 sum;

    *arg3 = 0xFFFF;
    *arg4 = 0xFFFF;
    *arg5 = 0xFFFFFF;
    n0 = &D_002214D8->f3018[arg0];
    n1 = &D_002214D8->f3018[arg1];
    e0 = &D_002214D8->f3010[n0->f8];
    e1 = &D_002214D8->f3010[n1->f8];
    area = &D_002214D8->f3030[e0->f8];
    if (((u16 *)area)[4] & 0x1000) {
        return;
    }
    ((u16 *)area)[4] |= 0x1000;
    if (arg0 == arg1) {
        *arg3 = arg0;
        *arg4 = 0;
        *arg5 = 0;
    } else if (e0->f8 == e1->f8) {
        if (n0->f8 == n1->f8) {
            func_0048D228(arg0, arg1, arg2, &a0, &a1, &aCost);
        } else {
            func_0048D330(arg0, arg1, arg2, &a0, &a1, &aCost);
        }
        if (a0 != 0xFFFF && aCost < *arg5) {
            *arg3 = a0;
            *arg4 = a1;
            *arg5 = aCost;
        }
    } else {
        it = &D_002214D8->f3038[area->f4];
        end = it + area->f6;
        for (; it != end; it++) {
            func_0048D758(it->f2, arg1, arg2, &b0, &b1, &bCost);
            if (b0 == 0xFFFF) {
                continue;
            }
            node = &D_002214D8->f3018[it->f0];
            if (arg0 == it->f0) {
                e = &D_002214D8->f3020[node->f4];
                eend = e + node->f6;
                for (; e != eend; e++) {
                    if (((u16 *)e)[0] == it->f2) {
                        c0 = ((u16 *)e)[0];
                        c1 = ((u16 *)e)[1];
                        cCost = ((u16 *)e)[2];
                        break;
                    }
                }
                if (e == eend) {
                    c0 = -1;
                }
            } else if (n0->f8 == node->f8) {
                func_0048D228(arg0, it->f0, arg2, &c0, &c1, &cCost);
            } else {
                func_0048D330(arg0, it->f0, arg2, &c0, &c1, &cCost);
            }
            if (c0 != 0xFFFF) {
                sum = bCost + cCost;
                if (sum > 0xFFFF) {
                    sum = 0xFFFF;
                }
                if (sum < *arg5) {
                    *arg3 = c0;
                    *arg4 = c1;
                    *arg5 = sum;
                }
            }
        }
    }
    ((u16 *)area)[4] &= 0xEFFF;
}
