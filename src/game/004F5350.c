#include "common.h"
int D_00220980 = 0;
typedef struct Type1 {
    char p[7];
    unsigned char f7;
} Type1;
extern Type1 D_00206948[];
extern int D_0021DDB4;
extern void func_004F53C0(void);
extern void func_004F5418(void);

void func_004F5350(void)
{
    if (D_00220980) {
        D_00206948[0].f7 = 0;
        if (D_00220980 < 25)
            func_004F53C0();
        else
            func_004F5418();
        D_00206948[0].f7 = 1;
        D_0021DDB4 = 6;
        D_00220980 = 0;
    }
}
