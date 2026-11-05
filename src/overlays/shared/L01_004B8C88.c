#include "common.h"

extern int func_005B4F70(void *, int);
extern void func_L01_00591BD8(void *, int, int);
int func_L01_004B8C88(void *arg0, int arg1) {
    unsigned char *state = *(unsigned char **)((char *)arg0 + 0xAC);
    if (arg1 == 4) {
        func_005B4F70(arg0, 2);
        if (state[0x60D] != 0) func_L01_00591BD8(arg0, 8, -1);
        else func_L01_00591BD8(arg0, 0x1A, -1);
    }
    return 1;
}
