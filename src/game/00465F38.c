#include "common.h"
extern char D_001718B0[], D_001718C8[], D_001718E0[], D_001718F8[], D_00171918[];
extern char D_00171938[], D_00171968[], D_00171988[], D_001719A8[];
extern char *func_0011AFC8(char *, const char *, u32);
void func_00465F38(const u8 *header)
{
    s32 i;
    u8 region;
    func_0011AFC8(D_001718B0, (const char *)header + 8, 21);
    region = header[0x12];
    if (region == 'E')
        D_001718C8[2] = region;
    else if (region == 'P')
        D_001718C8[2] = 'I';
    else if (region == 'K')
        D_001718C8[2] = region;
    for (i = 3; i < 7; ++i)
        D_001718C8[i] = header[i + 0xD];
    for (i = 8; i < 11; ++i)
        D_001718C8[i] = header[i + 0xD];
    for (i = 11; i < 13; ++i)
        D_001718C8[i] = header[i + 0xE];
    func_0011AFC8(D_001718E0, D_001718C8, 13);
    func_0011AFC8(D_001718F8, D_001718C8, 13);
    func_0011AFC8(D_00171918, D_001718C8, 13);
    func_0011AFC8(D_00171938, D_001718C8, 13);
    func_0011AFC8(D_00171938 + 20, D_001718C8, 13);
    func_0011AFC8(D_00171968, D_001718C8, 13);
    func_0011AFC8(D_001719A8, D_001718C8, 13);
    func_0011AFC8(D_00171988, D_001718C8, 13);
}
