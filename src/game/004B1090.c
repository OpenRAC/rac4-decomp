#include "common.h"
extern void func_004B1F38(void);
extern void func_004B15E8(void);
typedef struct Type1 {
    int f0, f4, f8;
    char p[0x2C];
    unsigned char f38;
} Type1;
extern Type1 D_00309650[];
/* Initialize the panel and start its positive selection. */
void func_004B1090(void)
{
    func_004B1F38();
    D_00309650[0].f38 = D_00309650[0].f8 = 1;
    if (D_00309650[0].f4 > 0)
        func_004B15E8();
}
