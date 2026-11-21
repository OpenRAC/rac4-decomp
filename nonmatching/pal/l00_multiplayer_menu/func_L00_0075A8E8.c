/* Not matching yet on PAL: 19/23 positional words match (82.61%); 4 differ, size 96/92 bytes (delta +4). */
/* cflags: -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_0075A8E8 nonmatching/pal/l00_multiplayer_menu/func_L00_0075A8E8.c --diff
 * Data ownership and callback target remain unverified; external storage changes the generated access sequence. */
#include "common.h"
extern void func_0047FEB0(int, int, int, int, int);
extern s32 D_0021DF08;
extern s32 D_0022168C;
void func_L00_0075A8E8(void *arg0)
{
    void *table;
    func_0047FEB0(16, 1, 1, 0, 0);
    D_0021DF08 = 6;
    table = *(void **)((u8 *)arg0 + 0x58);
    (*(void (**)(void *))((u8 *)table + 0x140))(arg0);
    D_0022168C = 3;
}