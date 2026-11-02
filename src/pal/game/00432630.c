#include "common.h"
typedef struct Type1 {
    int f0, f4;
} Type1;
extern Type1 D_003CEF90[];
typedef struct Type2 {
    char p[0x218];
    int f218;
} Type2;
extern Type2 D_001721E0[];
/* Invalidate the first matching recent entry. */
void func_00432630(int a)
{
    int i;
    Type1 *p = D_003CEF90;
    for (i = 0; i < 8; i++, p++)
        if (p->f0 == a && p->f4 > D_001721E0[0].f218 - 2000) {
            p->f0 = -1;
            return;
        }
}
