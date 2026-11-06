/* cflags: -mno-split-addresses */
#include "common.h"
extern void func_004D0038(void *, s32);
extern s32 func_004A1A60(void *, s32);
extern const char *func_0045E038(s32);
extern s32 func_00505238(u32, const char *);
extern u8 D_0021DE30[];
extern s32 D_002209DC;
void func_004D08B0(char *p, s32 reverse)
{
    func_004D0038(p, reverse);
    {
        u8 *value = &D_0021DE30[*(s32 *)p];
        if (*value == 8) {
            if (!reverse)
                ++*value;
            else
                --*value;
        }
    }
    if (p) {
        s32 id = func_004A1A60(*(char **)(p + 0x70) + 4, 2);
        const char *text = func_0045E038(*(s32 *)(p + (D_0021DE30[*(s32 *)p] << 2) + 0x1C));
        func_00505238(id, text);
    }
    D_002209DC = -D_0021DE30[*(s32 *)p];
}
