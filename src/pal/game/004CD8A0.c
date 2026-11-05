#include "common.h"

extern u8 D_0030EAA0[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 func_00506BB8(void);
extern const char *func_004CD9B8(void);
extern s32 func_004CDC60(s32);
extern void *func_0047DB88(s32);
extern s32 func_004CDE78(s32);
extern void *func_0054A290(s32, s32);
extern const char *func_0045E850(s32);

const char *func_004CD8A0(s32 a0)
{
    s32 *record = (s32 *)(D_0030EAA0 + func_00506BB8() * 100);
    s32 id;

    if (a0 == 8) {
        s32 table[6] = {0x32A8, 0x32A9, 0x32AA, 0x32AB, 0x32AC, 0x32AC};
        id = table[record[14]];
        goto done;
    }
    if (a0 == 9) {
        return func_004CD9B8();
    }
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        goto special;
    }
    if (a0 < 8) {
        id = *(s16 *)((u8 *)func_0047DB88(func_004CDC60(a0)) + 4);
        goto done;
    }
    id = *(s16 *)((u8 *)func_0054A290(func_004CDC60(a0), 0) + 0xA);
    goto done;

special:
    id = *(s16 *)((u8 *)func_0054A290(func_004CDE78(a0), 0) + 0xA);
done:
    return func_0045E850(id);
}
