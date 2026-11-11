#include "common.h"

void func_L00_0073F590(char *arg0) {
    char **p = (char **)(arg0 + 0xd4);
    s32 i;
    *(s32 *)(arg0 + 0x36C) = -1;
    i = 10;
    do {
        char *v;
        i--;
        v = *p;
        (*(void (**)(char *))((*(char **)(v + 0x58)) + 0xe4))(v);
        p++;
    } while (i >= 0);
}
