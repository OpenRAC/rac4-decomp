#include "common.h"

extern s32 func_L00_005BC980(void *p);
extern void func_L00_005F15B8(s32 arg0);
extern void func_L00_005F6AE0(void *p, s32 a, void *cb, s32 b, s32 c, s32 d, f32 f);
extern void func_L00_0066CC68(s32, s32);
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L01_005A1B38(void *p);
extern s32 func_L01_005AE158(void *p);
extern s32 func_L01_00626740(s32, void *);
extern void func_L01_003D7250(void);

typedef int u128 __attribute__((mode(TI)));

// Per-frame update of the linked object: clears its flags, runs the update
// calls, copies a source block into +0x500/+0x510 and returns 1.
s32 func_L01_003D6920(void *arg0) {
    unsigned char *s0;
    u8 v;
    void *p;
    void **tbl;
    s32 idx;

    s0 = *(unsigned char **)((char *)arg0 + 0xAC);
    s0[0x48A] = 0;
    v = ((unsigned char *)arg0)[0x20];
    if ((u32)(v - 0xE) < 2U || v == 0xC) {
        func_L00_0066CC68(1, (s32)arg0);
        return 0;
    }
    if (func_L01_00626740(1, arg0) == 0) {
        func_L00_0066D220(1, 4, arg0);
    }
    s0[0x4DC] = 0;
    if (func_L01_005AE158(arg0) != 0 && *(f32 *)(s0 + 0x348) > 0.0f && (u32)(s0[0x123] - 2) < 2U) {
        func_L00_0066D220(6, 0, arg0);
        func_L00_005F6AE0(arg0, 4, (void *)func_L01_003D7250, 0, 0, 0, 0.0f);
    }
    func_L00_005F15B8((s32)arg0);
    func_L01_005A1B38(arg0);
    p = *(void **)(s0 + 0x60);
    if (p != 0) {
        *(u128 *)(s0 + 0x500) = *(u128 *)(s0 + 0x50);
        *(u128 *)(s0 + 0x510) = *(u128 *)((unsigned char *)p + 0xF0);
        s0[0x4DC] = 1;
    } else {
        idx = *(s32 *)(s0 + 0x74);
        if (idx >= 0) {
            tbl = (void **)(s0 + 0xA0);
            if ((*(void **)((unsigned char *)tbl + (idx << 2)))) {
                *(u128 *)(s0 + 0x500) = *(u128 *)((unsigned char *)(*(void **)((unsigned char *)tbl + (idx << 2))) + 0x10);
                *(u128 *)(s0 + 0x510) = *(u128 *)((unsigned char *)(*(void **)((unsigned char *)tbl + (idx << 2))) + 0xF0);
                s0[0x4DC] = 1;
            }
        }
    }
    if (*(s32 *)(s0 + 0x4AC) >= 0) {
        if (func_L00_005BC980(s0 + 0x4AC) != 0) {
            s0[0x38F] = 0;
            *(s32 *)(s0 + 0x4AC) = -1;
        }
    }
    return 1;
}
