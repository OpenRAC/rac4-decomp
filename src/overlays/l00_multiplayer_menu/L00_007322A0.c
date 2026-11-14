#include "common.h"

extern void func_0011A9EC(void *, void *);
extern char *func_0011AFC8(char *, char *, s32);
extern u32 func_0011D878(s8 *arg0, u32 arg1, s8 *arg2, ...);
extern s32 func_L00_005C9F50(s32);
extern void *func_L00_00732250(s32 unused, s32 val, s16 *e, u32 n);
extern u8 D_00220FE0[];
extern u8 D_004E96E8[];
extern u8 D_004E9768[];

// Fills the entry at arg2 from the table row picked by arg1's kind, or from the fallback text.
void func_L00_007322A0(s32 arg0, s32 *arg1, u8 *arg2) {
    s32 *e;

    e = NULL;
    if (arg1[0] == 6) {
        e = func_L00_00732250(arg0, arg1[1], (s16 *)D_004E96E8, 8);
    } else if (arg1[0] == 7) {
        e = func_L00_00732250(arg0, arg1[1], (s16 *)D_004E9768, 0xB);
    }
    if (e != NULL) {
        func_0011D878(arg2, 0x50, (e[1] != -1) ? func_L00_005C9F50(e[1]) : D_00220FE0, arg1[1]);
        arg2[0x4F] = 0;
        func_0011AFC8(arg2 + 0x50, (e[2] != -1) ? func_L00_005C9F50(e[2]) : D_00220FE0, 0xA0);
        arg2[0xEF] = 0;
        func_0011AFC8(arg2 + 0xF0, (e[3] != -1) ? func_L00_005C9F50(e[3]) : D_00220FE0, 0xA0);
        arg2[0x18F] = 0;
        return;
    }
    func_0011A9EC(arg2, func_L00_005C9F50(0x11B1));
}
