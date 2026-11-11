#include "common.h"
extern char D_00321B98[];
extern s32 func_004E21D8(s32, s32, void *);
extern void func_004E0858(void);
extern s32 func_004FC650(void);
extern s32 func_00475858(f32, s32 *, s32, s32);
extern void func_004979A8(void *, s32, s32);
extern void func_004E19D8(s32, void *);
extern void func_00497980(s32);
void func_004DA960(void)
{
    char *p = D_00321B98;
    if (*(u8 *)(p + 0x13BD)) {
        *(u8 *)(p + 0x13BD) = 0;
        func_004E21D8(30, 4, 0);
        func_004E0858();
    }
    if (func_00475858(0.1f, (s32 *)(p + 0x1388), func_004FC650(), 1)) {
        func_004979A8(p + 0x1378, *(s32 *)(p + 0x1388), 0);
    } else {
        func_004E19D8(30, 0);
        if (*(u8 *)(p + 0x13BC)) {
            func_00497980(32);
            *(u8 *)(p + 0x13BC) = 0;
        }
        *(s32 *)(p + 4) &= ~4;
    }
}
