#include "pal/object_data.h"

extern s64 func_L05_004DD4D0(u8 *);
extern void func_L01_0059F8F8(u8 *, u8 *, s32, f32, f32);
extern void func_00487920(void *);
extern s32 func_L01_00598028(void *, f32, f32, f32);
extern void func_0047A158(void *, void *, s32, s32);
extern s32 D_L05_00222284;

/* Advances a live moby: bumps its counter, then plays the 0x4B0 effect and links 0x530. */
void func_L05_004DD110(u8 *arg0) {
    u8 *vars;
    u16 count;

    vars = (u8 *)((PalObject *)arg0)->data;
    if (func_L05_004DD4D0(arg0) != 0) {
        return;
    }
    if (arg0 == NULL || arg0[0x20] == 0xFE || arg0[0x20] == 0xFD) {
        return;
    }
    count = *(u16 *)(arg0 + 0x6A);
    if (count <= 0xFFFE) {
        *(u16 *)(arg0 + 0x6A) = count + 1;
    }
    func_L01_0059F8F8(arg0, vars + 0x4B0, 0, 0.0432f, 0.43200004f);
    func_00487920(arg0);
    func_L01_00598028(arg0, 40.0f, -1.0f, 0.0f);
    if (*(void **)(vars + 0x530) != NULL) {
        func_0047A158(arg0, *(void **)(vars + 0x530), 1, D_L05_00222284);
    }
}
