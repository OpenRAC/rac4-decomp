#include "common.h"

typedef struct Type1 {
    u8 pad0[0x1A8];
    s32 f1A8;
    u8 pad1[0x5C0 - 0x1AC];
} Type1;

extern void func_L00_007180A0(s32 arg0, s32 arg1);
extern void func_L00_007647B0(s32 identifier);
extern Type1 D_1EE600[];

/* Steps each active slot's selection by its direction flags, wrapping within the count. */
void func_L00_00747C60(u8 *arg0) {
    u32 i;
    s32 *p;
    s32 *q;
    u8 *flags;
    Type1 *tbl;
    s32 d;
    s32 f;

    if (arg0[0x299] != 0) {
        i = 0;
        tbl = D_1EE600;
        flags = arg0 + 0x294;
        p = (s32 *)(arg0 + 0x284);
        q = (s32 *)(arg0 + 0x264);
        for (; i < 4; i++) {
            s32 id = q[i];
            if (~id != 0 && flags[i] == 0) {
                f = tbl[id].f1A8;
                if (f & 0x4000) {
                    d = -1;
                } else if (f & 0x1000) {
                    d = 1;
                } else {
                    d = 0;
                }
                if (d != 0) {
                    func_L00_007647B0(0x58);
                    p[i] += d;
                    if (p[i] < 0) {
                        p[i] += *(s32 *)(arg0 + 0x260);
                    }
                    p[i] %= *(s32 *)(arg0 + 0x260);
                    func_L00_007180A0(p[i], i);
                }
            }
        }
    }
}
