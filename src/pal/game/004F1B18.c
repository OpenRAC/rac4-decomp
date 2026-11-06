#include "common.h"
/* Control-flow reference: OpenRAC RAC3 func_003ABE98, 3ABA48.c,
 * commit 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde (GPL-3.0).
 * PAL addresses, physical signatures and wrapping arithmetic checked independently. */
typedef struct {
    u8 unknown0[8];
    u32 sector;
} DiscFile;
s32 D_002209B0 = 0;
extern const char D_003D3228[];
extern const char D_003D3240[];
extern s32 func_00126E20(s32 mode);
extern s32 func_00159498(s32 mode);
extern s32 func_00137FB0(void);
extern s32 func_0011D5D8(const char *format, ...);
extern s32 func_001593D8(u32 sector, s32 count, void *buffer, const u8 *mode);
s32 func_004F1B18(DiscFile *file, void *buffer, s32 bytes)
{
    s32 result;
    u8 mode[3];
    result = 0;
    if (D_002209B0 != 0) {
        func_00126E20(2);
        if (func_00159498(1) == 0) {
            D_002209B0 = 0;
            if (func_00137FB0() == 0) {
                result = (s32)((u32)(bytes >> 11) << 11);
                file->sector += (u32)(bytes >> 11);
            } else {
                func_0011D5D8(D_003D3228);
            }
        }
    } else {
        mode[0] = 100;
        mode[1] = 0;
        mode[2] = 0;
        func_00159498(0);
        if (func_001593D8(file->sector, bytes >> 11, buffer, mode) != 0) {
            D_002209B0 = 1;
        } else {
            func_0011D5D8(D_003D3240);
        }
        result = 0;
    }
    return result;
}
