/* Not matching yet on PAL: 23/23 positional words match (100.00%); 0 differ, size 92/92 bytes (delta 0). */
/* cflags: -O2 -G8 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_00739470 nonmatching/pal/l00_multiplayer_menu/func_L00_00739470.c --diff
 * PAL data name D_00220AD0 conflicts with an existing C declaration; callee prototypes conflict with mapped definitions. */
#include "common.h"
typedef s32 M2C_UNK;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

M2C_UNK func_L00_0070DEB0(s32);                     /* extern */
M2C_UNK func_L00_0070DF20(s32);                     /* extern */
M2C_UNK func_L00_0071F2E0(s32);                     /* extern */
M2C_UNK func_L00_0071FCE8(s32);                     /* extern */
extern s8 D_00220AD0;
extern s8 D_00220AD1;
extern void *D_002234A4;

void func_L00_00739470(s32 arg0) {
    D_00220AD0 = 0;
    D_00220AD1 = 0;
    func_L00_0070DF20(0);
    func_L00_0070DEB0(0);
    M2C_FIELD(M2C_FIELD(D_002234A4, void **, 0x44), s8 *, 0x14) = 0;
    func_L00_0071F2E0(arg0);
    func_L00_0071FCE8(arg0);
}
