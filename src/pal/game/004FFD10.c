#include "common.h"
extern int func_004FFCF0(void);
extern void func_00163990(void);
extern void func_004FFA10(void);
typedef struct Type1 {
    char p[8];
    int f8;
    char q[0x18];
    int f24;
} Type1;
extern Type1 D_00171228[];
/* Complete the active operation and move to its finished state. */
void func_004FFD10(void)
{
    if (func_004FFCF0()) {
        func_00163990();
        D_00171228[0].f8 = 2;
        D_00171228[0].f24 = 7;
        func_004FFA10();
    }
}
