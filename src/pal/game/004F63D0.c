#include "common.h"
int D_00220A20 = 0;
typedef struct Type1 {
    char p[7];
    unsigned char f7;
} Type1;
extern Type1 D_002069D0[];
extern int D_0021DE3C;
extern void func_004F6440(void);
extern void func_004F6498(void);
/* Apply the pending panel choice and clear its request. */
void func_004F63D0(void)
{
    if (D_00220A20) {
        D_002069D0[0].f7 = 0;
        if (D_00220A20 < 25)
            func_004F6440();
        else
            func_004F6498();
        D_002069D0[0].f7 = 1;
        D_0021DE3C = 6;
        D_00220A20 = 0;
    }
}
