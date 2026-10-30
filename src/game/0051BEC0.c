#include "common.h"

/* Passes the float at 0x1784 and the float at 0x1780 to func_004757A0, with the first float parameter as a third argument when the first float is below the second, else the second float parameter. */
extern void func_004757A0(void *, f32, f32);

void func_0051BEC0(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f12;

    temp_f12 = *(f32 *)((u8 *)arg0 + 0x1780);
    if (*(f32 *)((u8 *)arg0 + 0x1784) < temp_f12) {
        func_004757A0((u8 *)arg0 + 0x1784, temp_f12, fparg0);
        return;
    }
    func_004757A0((u8 *)arg0 + 0x1784, temp_f12, fparg1);
}
