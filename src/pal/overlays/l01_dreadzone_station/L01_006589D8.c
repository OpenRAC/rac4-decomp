/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"
extern u8 D_0017123D;
extern s32 func_L00_00699C48(u32, s32);
extern s32 func_L01_00658558(u32);
extern s32 func_L01_00658650(s32);

s32 func_L01_006589D8(s32 index, s32 mode)
{
    if (D_0017123D != 0) {
        if (mode != 0)
            return func_L00_00699C48((u32)index, 1);
        return func_L01_00658650(index);
    }
    return func_L01_00658558((u32)index);
}
