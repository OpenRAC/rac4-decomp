/* Not matching yet on PAL: 12/27 positional words match (44.44%); 15 differ, size 108/108 bytes (delta 0). */
/* cflags: -O2 -G8 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_00715F50 nonmatching/pal/l00_multiplayer_menu/func_L00_00715F50.c --diff
 * Instruction order and registers differ; the callee signature and layouts are inferred. */
#include "common.h"
typedef s32 M2C_UNK;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

M2C_UNK func_L00_00714610();                        /* extern */

void func_L00_00715F50(void *arg0, void *arg1) {
    func_L00_00714610();
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) M2C_FIELD(arg1, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) M2C_FIELD(arg1, s32 *, 0x44);
    M2C_FIELD(arg0, s32 *, 0x7C) = 0x80808080;
    M2C_FIELD(arg0, u8 *, 0x6C) = (u8) M2C_FIELD(arg1, u8 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0x70) = -1;
    M2C_FIELD(arg0, s32 *, 0x64) = -1;
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s8 *, 0x78) = 0;
}
