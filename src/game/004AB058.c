#include "common.h"

extern void func_00496B28(s32 *arg0, s32 arg1);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505AD8(s32 a);
extern s32 func_00505B20(void);
typedef struct Type1 {
    char pad[0x158];
    s32 f158;
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
} Type1;
extern Type1 D_308B80[];

/* Resets one record's fields, disables four flags and runs the mode-7 pass on the record. */
void func_004AB058(s32 index) {
    s32 saved;

    saved = func_00505B20();
    func_00505AD8(index);
    D_308B80[index].f158 = -1;
    D_308B80[index].f15C = 0;
    D_308B80[index].f160 = 0;
    D_308B80[index].f168 = 0;
    func_00504F68(0x7000B, 0);
    func_00504F68(0x7000C, 0);
    func_00504F68(0x70009, 0);
    func_00504F68(0x7000A, 0);
    func_00496B28((s32 *)&D_308B80[index], 7);
    func_00505AD8(saved);
}
