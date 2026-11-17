/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_01E9C0B0(void *);
extern void func_L00_00566910(void *);
extern s32 D_004A9B94[];
extern void *D_004A9B98[];
extern void *D_004A9B9C[];

// Unlinks an object from a list, then frees its parts and the object itself.
void func_L00_005670A8(u8 *a0) {
    u8 *prev;
    u8 *next;

    prev = *(u8 **)(a0 + 0x4);
    next = *(u8 **)(a0 + 0x0);
    if (prev != NULL) {
        *(u8 **)prev = next;
        next = *(u8 **)(a0 + 0x0);
        prev = *(u8 **)(a0 + 0x4);
    } else {
        D_004A9B98[0] = next;
    }
    if (next != NULL) {
        *(u8 **)(next + 0x4) = prev;
    } else {
        D_004A9B9C[0] = prev;
    }
    func_01E9C0B0(a0 + 0x14);
    func_L00_00566910(*(void **)(a0 + 0x50));
    func_L00_00566910(a0);
    D_004A9B94[0] -= 1;
}
