/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EE7860(void *, s32);
extern s32 func_01EEE1FC(void);
extern s32 func_01EEED28(u8 *a0);
extern void func_01F08B94(s32);

/* Update two stored objects, then call a virtual method with the state. */
void func_01EEF28C(u8 *a0, s32 *a1) {
    s32 v;
    v = *(s32 *)(a0 + 0xA4);
    if (*(s32 *)(v + 0x3A30) != 0) {
        if (*a1 == 0) {
            *a1 = v;
        }
        func_01EE7860(*(void **)(a0 + 0xA4), 1);
    }
    v = *(s32 *)(a0 + 0xA8);
    if (*(s32 *)(v + 0x3A30) != 0) {
        *a1 = v;
        func_01EE7860(*(void **)(a0 + 0xA8), 1);
    }
    if (*(s32 *)(a0 + 0x30CC) != 0) {
        if (*(s32 *)(a0 + 0xAC) != 0) {
            func_01F08B94(*(s32 *)(a0 + 0xAC));
        }
    }
    if (func_01EEED28(a0) == 0) {
        s32 obj = func_01EEE1FC();
        ((void (*)(s32, s32, f32, f32, f32, f32, s32))(*(s32 **)obj)[0x98 / 4])(obj, *(s32 *)a0, *(f32 *)(a0 + 4), *(f32 *)(a0 + 8), *(f32 *)(a0 + 0xC), *(f32 *)(a0 + 0x10), *(s32 *)(a0 + 0x14));
    }
}
