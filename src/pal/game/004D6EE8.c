#include "common.h"
extern char D_0031D100[];
extern int func_00506BB8(void);
extern void func_00502520(void *), func_004D6FB0(void), func_004D7408(void), func_004D7208(void);
extern int func_004A2468(void *);
void func_004D6EE8(void *descriptor)
{
    char *p = D_0031D100 + func_00506BB8() * 0x528;
    switch (*(int *)p) {
    case 0:
        *(int *)p = 2;
        break;
    case 1:
        func_00502520(descriptor);
        break;
    case 2:
        func_004D6FB0();
        break;
    }
    if (*(int *)(p + 4) & 1)
        func_004D7408();
    func_004A2468(p + 0x4BC);
    if (*(int *)(p + 4) & 2)
        func_004D7208();
}
