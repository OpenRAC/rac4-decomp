#include "common.h"
extern unsigned char D_0021EE98;
int D_0021FACC = 1;
extern int func_004E3138(int, int, void *);
extern void func_004CB038(int, int);
void func_004CBF18(int a)
{
    if (a) {
        if (D_0021EE98) {
            D_0021FACC = 1;
            func_004E3138(14, 0, 0);
            func_004CB038(2, 0);
        } else
            func_004CB038(15, 0);
    } else {
        func_004E3138(12, 0, 0);
        func_004CB038(1, 0);
    }
}
