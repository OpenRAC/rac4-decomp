#include "common.h"
extern void func_004B2DC8(void);
extern void func_004B2478(void);
typedef struct Type1 {
    int f0, f4, f8;
    char p[0x2C];
    unsigned char f38;
} Type1;
extern Type1 D_00309750[];
/* Initialize the panel and start its positive selection. */
void func_004B1F20(void)
{
    func_004B2DC8();
    D_00309750[0].f38 = D_00309750[0].f8 = 1;
    if (D_00309750[0].f4 > 0)
        func_004B2478();
}
