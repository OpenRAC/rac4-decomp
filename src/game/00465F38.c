#include "common.h"
extern char D_00171830[], D_00171848[], D_00171860[], D_00171878[], D_00171898[];
extern char D_001718B8[], D_001718E8[], D_00171908[], D_00171928[];
extern char *func_0011AFC8(char *, const char *, u32);
void func_00465F38(const u8 *header)
{
    s32 i;
    u8 region;
    func_0011AFC8(D_00171830, (const char *)header + 8, 21);
    region = header[0x12];
    if (region == 'E')
        D_00171848[2] = region;
    else if (region == 'P')
        D_00171848[2] = 'I';
    else if (region == 'K')
        D_00171848[2] = region;
    for (i = 3; i < 7; ++i)
        D_00171848[i] = header[i + 0xD];
    for (i = 8; i < 11; ++i)
        D_00171848[i] = header[i + 0xD];
    for (i = 11; i < 13; ++i)
        D_00171848[i] = header[i + 0xE];
    func_0011AFC8(D_00171860, D_00171848, 13);
    func_0011AFC8(D_00171878, D_00171848, 13);
    func_0011AFC8(D_00171898, D_00171848, 13);
    func_0011AFC8(D_001718B8, D_00171848, 13);
    func_0011AFC8(D_001718B8 + 20, D_00171848, 13);
    func_0011AFC8(D_001718E8, D_00171848, 13);
    func_0011AFC8(D_00171928, D_00171848, 13);
    func_0011AFC8(D_00171908, D_00171848, 13);
}
