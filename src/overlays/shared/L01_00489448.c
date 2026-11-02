#include "common.h"

typedef void (*Handler)(void *, void *);

extern Handler *func_00588670(s32, s32, s32);
extern void func_00591BD8(void *, s32, s32);
extern void func_00626818(void *, s32);
extern void func_L01_00588B08(void *);
extern void func_L01_00593D50(void *, f32, f32, f32);
extern u8 D_003AA270[];

// Step an object's state (byte 0x20): set its flags and mode, or wait until the counter at 0x6A reaches 601 in state 3 before doing so.
void func_L01_00489448(u8 *arg0) {
    switch (arg0[0x20]) {
    case 0: {
        Handler *h = func_00588670(0x2090, 0, 4);
        if (h != NULL) {
            (*h)(arg0, D_003AA270);
        }
        func_00591BD8(arg0, 1, -1);
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_00626818(arg0, 1);
        *(u16 *)(arg0 + 0x34) |= 2;
        func_L01_00588B08(arg0);
        break;
    }
    case 1:
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_00626818(arg0, 1);
        *(u16 *)(arg0 + 0x34) |= 2;
        break;
    case 2:
        func_L01_00593D50(arg0, 40.0f, -1.0f, 0.0f);
        break;
    case 3:
        if (++*(u16 *)(arg0 + 0x6A) >= 0x259) {
            func_00591BD8(arg0, 1, -1);
            *(s32 *)(arg0 + 0x98) = 0;
            *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
            func_00626818(arg0, 1);
            *(u16 *)(arg0 + 0x34) |= 2;
            func_L01_00588B08(arg0);
        }
        break;
    }
}
