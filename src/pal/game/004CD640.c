#include "common.h"

extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_0021DE98;
extern s32 D_0021F218;
extern u32 D_00171C94[];
extern s32 func_00506BB8(void);
extern u8 *func_00511CC0(s32 player);
extern s32 func_004CDE78(s32 category);
extern s32 func_004CDC60(s32 category);
extern u8 *func_0047DE20(void);
extern s32 func_0047DBB0(s32 level);
extern s32 func_0054A308(const void *progress, s32 level);

s32 func_004CD640(s32 category)
{
    u8 *player;
    u8 *scenario;
    s32 level;

    if ((u32)category - 8 < 2) {
        return 1;
    }
    if (category < 8) {
        if (D_0021EE54 == 0 && D_0021EE58 == 1) {
            player = func_00511CC0(func_00506BB8());
            level = func_004CDE78(category);
            return func_0054A308(*(void **)(player + 0x26E4), level);
        }
        scenario = func_0047DE20();
        if (scenario != 0 && *(s32 *)(scenario + 0x1D0) == 0) {
            return 0;
        }
        if (D_0021DE98 == 1 && D_0021F218 == 0 &&
            (D_00171C94[0] & 0x10000000) == 0) {
            return 0;
        }
        return func_0047DBB0(func_004CDC60(category));
    } else {
        player = func_00511CC0(func_00506BB8());
        level = func_004CDC60(category);
        return func_0054A308(*(void **)(player + 0x26E4), level);
    }
}
