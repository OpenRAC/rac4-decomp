#include "common.h"

/* PAL: from rac3-decomp's func_L39_0068FA28, constants adapted */
void func_L00_007229C8(char *arg0) {
    char **p = (char **)(arg0 + 0xd4);
    s32 i;
    *(s32 *)(arg0 + 0x2774) = -1;
    i = 10;
    do {
        char *v;
        i--;
        v = *p;
        (*(void (**)(char *))((*(char **)(v + 0x58)) + 0xe4))(v);
        p++;
    } while (i >= 0);
}
