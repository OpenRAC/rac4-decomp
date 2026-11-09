#include "common.h"

typedef struct { s32 v; s32 f4; s32 f8; } Ent;
extern s32 func_00465C08(u8 *);
extern s32 D_0021DDB4;
extern s32 D_0021EDC4;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021EEB4;
extern u8 D_003D7D70[];
extern Ent D_00270040[];
extern u8 *D_003367B8[];
s32 D_0021F2E8 = 0;
s32 D_0021F2EC = 0;
u8 *D_0021F2F0 = 0;
s32 D_0021F2F4 = 0;

/* Validates a request against the current state and, on success, records it (pushing the previous one when arg1 is 1). */
s32 func_0047F568(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 ret;
    s32 i;
    s32 n;
    u8 v;
    u8 *p;

    if (arg4 != 0) {
        *arg4 = 0;
    }
    ret = (D_0021EDC4 ^ -2) ? -1 : 0;
    if (arg1 == 1) {
        if (D_0021F2F4 >= 8) {
            ret = -2;
        }
    }
    if (arg0 >= 0) {
        v = D_003D7D70[arg0];
    } else {
        v = 0;
    }
    if (v != 0) {
        ret = -3;
    }
    if (D_0021EDD4 != 1) {
        n = 0;
        i = 0;
        p = D_003367B8[0];
        while (i < 10) {
            if (p != 0 && *(f32 *)(p + 0x2E20) == 0.0f) {
                n++;
                if (D_0021DDB4 != 0 || func_00465C08(p) != 3) {
                    if (D_0021EDD4 != 0 || D_0021EDD8 != 1 || n >= 2 || D_0021EEB4 == 0) {
                        ret = -4;
                        break;
                    }
                }
            }
            i++;
            p = D_003367B8[i];
        }
    }
    if (ret == 0) {
        if (arg1 == 1) {
            s32 k = D_0021F2F4;
            D_0021F2F4 = k + 1;
            D_00270040[k].v = D_0021DDB4;
            D_00270040[k].f4 = D_0021F2E8;
            D_00270040[k].f8 = D_0021F2EC;
        }
        D_0021EDC4 = arg0;
        D_0021F2E8 = arg2;
        D_0021F2EC = arg3;
        D_0021F2F0 = arg4;
    }
    return ret;
}
