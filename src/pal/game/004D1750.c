/* cflags: -mno-split-addresses */
#include "common.h"
extern void func_004D0ED8(void *, s32);
extern s32 func_004A2798(void *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern u8 D_0021DEB8[];
extern s32 D_00220A7C;
void func_004D1750(char *p, s32 reverse)
{
    func_004D0ED8(p, reverse);
    {
        u8 *value = &D_0021DEB8[*(s32 *)p];
        if (*value == 8) {
            if (!reverse)
                ++*value;
            else
                --*value;
        }
    }
    if (p) {
        s32 id = func_004A2798(*(char **)(p + 0x70) + 4, 2);
        const char *text = func_0045E850(*(s32 *)(p + (D_0021DEB8[*(s32 *)p] << 2) + 0x1C));
        func_005062D0(id, text);
    }
    D_00220A7C = -D_0021DEB8[*(s32 *)p];
}
