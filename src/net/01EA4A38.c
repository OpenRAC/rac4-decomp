/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern s32 func_01EA4570(u32 index);
extern s32 D_00167F3C[];

// Matches the entry at arg0, or entries 0 to 3 when arg0 is NULL, through the callbacks at D_00167F3C; sets *arg1 to 1 on a match.
s32 func_01EA4A38(u8 *arg0, s32 *arg1) {
    u16 sp0 = 0xFFFE;
    u16 sp2 = 0xFFFE;
    s32 i;
    u8 *entry;

    if (arg1 == NULL) {
        return 0x17;
    }
    *arg1 = 0;
    if (arg0 == NULL) {
        i = 0;
        do {
            entry = (u8 *)func_01EA4570(i++);
            if (entry != NULL) {
                s32 **tbl = (s32 **)D_00167F3C;
                if (((s32 (*)(s32, u16 *))(*tbl)[6])(*(s32 *)(entry + 0x474), &sp0) != 0) {
                    return 0x25;
                }
                if (((s32 (*)(s32, u16 *))(*tbl)[5])(*(s32 *)(entry + 0x474), &sp2) != 0) {
                    return 0x25;
                }
                if (sp2 != 0xFFFE && sp0 == sp2) {
                    *arg1 = 1;
                    break;
                }
            }
        } while (i < 4);
        return 0;
    }
    {
        s32 **tbl = (s32 **)D_00167F3C;
        if (((s32 (*)(s32, u16 *))(*tbl)[6])(*(s32 *)(arg0 + 0x474), &sp0) != 0) {
            return 0x25;
        }
        if (((s32 (*)(s32, u16 *))(*tbl)[5])(*(s32 *)(arg0 + 0x474), &sp2) != 0) {
            return 0x25;
        }
    }
    if (sp2 != 0xFFFE && sp0 == sp2) {
        *arg1 = 1;
    }
    return 0;
}
