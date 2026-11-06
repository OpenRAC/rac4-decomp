#include "common.h"
typedef struct Type1 {
    int f0, f4;
} Type1;
extern Type1 D_003CEF90[];
#include "pal/profile_001721E0.h"
/* Invalidate the first matching recent entry. */
void func_00432630(int a)
{
    int i;
    Type1 *p = D_003CEF90;
    for (i = 0; i < 8; i++, p++)
        if (p->f0 == a && p->f4 > (s32)(D_001721E0.region20.words.f218 - 2000U)) {
            p->f0 = -1;
            return;
        }
}
