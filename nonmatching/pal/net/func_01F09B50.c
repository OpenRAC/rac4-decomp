/* Not matching yet: 25/27 (92.59%) relocation-masked positional words; 108/108 candidate/target bytes. Branch-likely instructions differ; return declaration, global allocation and input bounds remain unproved. Reproduce: python tools/check_func.py --version pal func_01F09B50 nonmatching/pal/net/func_01F09B50.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -mno-split-addresses -Wuninitialized */
#include "common.h"

/* 25/27 target words match (92.59%) under relocation-masked positional
 * comparison; 108/108 bytes. Two branch-likely instructions differ.
 * The pointer must cover offsets through 0x8BB7; callee return declarations
 * conflict elsewhere and global allocation remains unknown. Verify with
 * tools/diff_func.py --version pal func_01F09B50. */
extern s32 func_01F0C090(void *, s32);
extern char D_0019E4F0[];
s32 func_01F09B50(u8 *arg0) {
    u8 *a = arg0 + 0x8B90;
    u8 *b = arg0 + 0x8BA8;
    s32 result = 0;
    if (*(s32 *)(a+12) == 0 && *(s32 *)(b+12) == 0) {
        if (*(s32 *)(a+4) != 0 || *(s32 *)(b+4) != 0)
            func_01F0C090(D_0019E4F0, 920);
        result = 1;
    }
    return result;
}
