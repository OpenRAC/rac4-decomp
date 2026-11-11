/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004DFB88 (src/levels/39_multiplayer_menu/L39_004DF158.c, GPL-3.0), the same code in both games. */

typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buf[64];
    s32 len;
} Type1;
typedef struct { u8 b[64]; } __attribute__((packed)) Type2;
extern void func_L00_0051BB50();
extern void *func_0011A370(void *, const void *, unsigned int);
void func_L00_0051B988(Type1 *c, u8 *data, u64 len) {
    u8 *buf = c->buf;
    u64 old;
    u64 new;
    s32 n;
    if (len == 0)
        return;
    old = c->count[0];
    new = (old + (len << 3)) & 0xFFFFFFFF;
    if (new < old)
        c->count[1]++;
    c->count[1] += len >> 29;
    c->count[0] = new;
    if (c->len != 0) {
                if (c->len + len < 64) {
            n = len;
            func_0011A370(buf + c->len, data, n);
            c->len += n;
            return;
        }
        n = 64;
        n -= c->len;
        func_0011A370(buf + c->len, data, n);
        func_L00_0051BB50(c, buf);
        len -= n;
        data += n;
        c->len = 0;
    }
    while (len >= 64) {
        len -= 64;
        *(Type2 *)buf = *(Type2 *)data;
        func_L00_0051BB50(c, buf);
        data += 64;
    }
    c->len = len;
    if (len != 0)
        func_0011A370(buf, data, len);
}
typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buf[64];
    s32 len;
} Type3;
extern void func_L00_0051BB50(Type3 *, u8 *);
