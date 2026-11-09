/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad[0x240];
    u64 sp[8][64];
} Type1;

extern Type1 *func_00517808(void);

#define ROTATE(a, n) (((a) >> (n)) + ((a) << (32 - (n))))

#define ROUND(LL, R, S) {                    \
    Type1 *tab = func_00517808();                     \
    u = R ^ s[S];                                \
    t = R ^ s[S + 1];                            \
    t = ROTATE(t, 4);                            \
    LL ^= tab->sp[0][(u >> 2) & 0x3f] ^          \
          tab->sp[2][(u >> 10) & 0x3f] ^         \
          tab->sp[4][(u >> 18) & 0x3f] ^         \
          tab->sp[6][(u >> 26) & 0x3f] ^         \
          tab->sp[1][(t >> 2) & 0x3f] ^          \
          tab->sp[3][(t >> 10) & 0x3f] ^         \
          tab->sp[5][(t >> 18) & 0x3f] ^         \
          tab->sp[7][(t >> 26) & 0x3f]; }

void func_L00_0053E428(u64 *data, u64 *ks, s32 enc) {
    u64 l, r, t, u;
    s32 i;
    u64 *s;

    r = data[0];
    l = data[1];
    r = ROTATE(r, 29) & 0xffffffff;
    l = ROTATE(l, 29) & 0xffffffff;
    s = ks;
    if (enc) {
        for (i = 0; i < 32; i += 8) {
            ROUND(l, r, i + 0);
            ROUND(r, l, i + 2);
            ROUND(l, r, i + 4);
            ROUND(r, l, i + 6);
        }
    } else {
        for (i = 30; i > 0; i -= 8) {
            ROUND(l, r, i - 0);
            ROUND(r, l, i - 2);
            ROUND(l, r, i - 4);
            ROUND(r, l, i - 6);
        }
    }
    data[0] = ROTATE(l, 3) & 0xffffffff;
    data[1] = ROTATE(r, 3) & 0xffffffff;
}
