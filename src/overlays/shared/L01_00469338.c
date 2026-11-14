#include "common.h"

/* Fetch two vectors (kinds 0 and 1) for the object and pass them, with the byte at +0x288 of the linked object (offset by the halfword at +0x4FE) converted to float, to func_L01_00469420. */
typedef int u128 __attribute__((mode(TI)));
extern void func_L00_005DE048(void *, s32, void *);
extern void func_L01_00469420(void *, u128, u128, f32);

void func_L01_00469338(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    s16 off = *(s16 *)(linked + 0x4FE);
    f32 value = (f32)(linked + off)[0x288];
    u128 first;
    u128 second;

    func_L00_005DE048(object, 0, &first);
    func_L00_005DE048(object, 1, &second);
    func_L01_00469420(object, first, second, value);
}
