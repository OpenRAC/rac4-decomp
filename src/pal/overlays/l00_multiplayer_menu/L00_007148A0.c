/* C adapted from rac3-decomp func_L39_0067F8B0 (commit cd0e7c20fd8a). */
#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);

void func_L00_007148A0(char *object, char *input)
{
    if (input != NULL) {
        func_0011AFC8(object + 0x18, input, 0x33);
        object[0x4B] = 0;
    }
}
