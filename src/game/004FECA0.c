#include "common.h"
extern int func_004FEC80(void);
extern void func_001638E8(void);
extern void func_004FE9A0(void);
typedef struct Type1 {
    char p[8];
    int f8;
    char q[0x18];
    int f24;
} Type1;
extern Type1 D_001711A8[];
/* Complete the active operation and move to its finished state. */
void func_004FECA0(void)
{
    if (func_004FEC80()) {
        func_001638E8();
        D_001711A8[0].f8 = 2;
        D_001711A8[0].f24 = 7;
        func_004FE9A0();
    }
}
