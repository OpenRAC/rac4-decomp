#include "common.h"

extern int D_22B4D0[];

/* Finds an entry in D_22B4D0 by searching for a halfword value at offset 0x86. */
void *func_0043A518(int arg0, int arg1) {
    unsigned char *ptr;
    int i;

    ptr = (unsigned char *)&D_22B4D0 + arg0 * 0x2100;
    for (i = 0; i < 0x30; i++) {
        if (*(short *)(ptr + 0x86) == arg1) {
            return ptr;
        }
        ptr += 0xB0;
    }
    return 0;
}
