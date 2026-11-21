/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { s32 a; s32 b; } S;
s32 func_003FE8B0(s32, S **, s32);
void func_003FE6F0(s32, s32, S *);
extern char D_003CCEE0[];
void func_00408528(s32 a0, s32 a1, s32 a2) {
    S *p;
    if (func_003FE8B0(a0, &p, 8) == 0) {
        p->a = a1;
        p->b = a2;
        func_003FE6F0(a0, (s32)D_003CCEE0, p);
    }
}
