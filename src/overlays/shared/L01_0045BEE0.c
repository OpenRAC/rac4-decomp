#include "common.h"

extern s32 func_L01_0045B378(void *);
extern char D_003A6B00[];
extern char D_003A6B30[];
extern char D_003A6B60[];
extern char D_003A6B90[];

char *func_L01_0045BEE0(u8 *arg0) {
    if (arg0[0x67] == 3) {
        return D_003A6B90;
    }
    switch (func_L01_0045B378(arg0)) {
    case 1: return D_003A6B00;
    case 5: return D_003A6B60;
    case 0:
    case 2:
    case 3:
    case 4:
    default: return D_003A6B30;
    }
}
