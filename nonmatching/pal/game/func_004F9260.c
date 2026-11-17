/* Not matching yet: 2/17 (11.76%) relocation-masked positional words; 72/68 candidate/target bytes. One extra word is emitted; existing global owner is referenced by extern. Reproduce: python tools/check_func.py --version pal func_004F9260 nonmatching/pal/game/func_004F9260.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern u8 *D_00220A94;
extern u8 D_00222100;
extern s32 D_0021DF58;
s32 func_004F9260(void) {
    u8 flag;
    s32 result;
    u8 *ptr;
    D_0021DF58 = 0;
    ptr = D_00220A94;
    flag = ptr[0x57];
    if (flag || ptr[0x68]) {
        result = D_00222100;
        if (result) {
            result = 1;
            if (flag) D_0021DF58 = result;
        }
    } else result = D_00222100;
    return result;
}
