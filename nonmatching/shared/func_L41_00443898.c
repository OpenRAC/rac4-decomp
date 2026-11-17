/* Not matching yet: SIZE ours 48 / retail 44 (one arm of a 72-byte function; joins func_L41_004438C4) (tools/try_func.py func_L41_00443898 --diff). Not part of the build. */
#include "common.h"

extern s32 D_0021E694;
extern s32 D_0021E698;

s32 func_L41_00443898(void)
{
    if (D_0021E694 == 1) {
        s32 value = D_0021E698;
        if (value != 0) return value;
    }
    return 0;
}
