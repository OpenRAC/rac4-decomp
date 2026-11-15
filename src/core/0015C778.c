#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void *func_0011A518(void *, s32, s32);

typedef struct {
    s32 w[5];
    u8 *f14;
    s32 f18;
} S3;

typedef struct {
    s32 f0;
    S3 h;
    u8 buf[0x400];
} S2;

extern void func_0015C828(S2 *);

// Build a request record in a local buffer from the argument and a bounded payload, then submit it.
void func_0015C778(S3 *arg0) {
    S2 loc;
    u32 n;

    func_0011A518(&loc, 0, 0x420);
    n = 0x400;
    if (*(u16 *)((u8 *)arg0 + 0x12) < 0x401) {
        n = *(u16 *)((u8 *)arg0 + 0x12);
    }
    func_0011A370(loc.buf, arg0->f14, n);
    loc.h = *arg0;
    loc.h.f14 = loc.buf;
    func_0015C828(&loc);
}
