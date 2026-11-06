/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern int func_00506BB8(void);
extern int func_00499120(int);
extern void func_0049BF40(int);
extern void func_004D2CB0(s32);
extern void func_L00_0065D120(void);

/* Dispatch the current mode to the corresponding overlay operation. */
void func_L00_0065D090(void)
{
    int flag = 0;
    int saved = func_00506BB8();
    switch (func_00499120(6)) {
    case 2: func_0049BF40(saved); break;
    case 5: flag = 1;
    case 6: func_004D2CB0(flag); break;
    case 13: func_L00_0065D120(); break;
    case 1: case 3: case 4: case 7: case 8: case 9:
    case 10: case 11: case 12: default: return;
    }
}
