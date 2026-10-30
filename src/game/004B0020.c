#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 f8;
    s32 fC;
    s32 f10;
} Type1;

extern void func_004B0D18(void);
extern void func_004B0970();
extern Type1 D_3095B0[];

/* Resets the D_3095B0 entry, then calls func_004B0970 with its saved value if that is not negative. */
void func_004B0020(void) {
    Type1 *p;
    s32 one;

    func_004B0D18();
    one = 1;
    p = D_3095B0;
    p->f4 = one;
    p->f8 = one;
    p->fC = -1;
    if (p->f10 >= 0) {
        p->fC = p->f10;
        func_004B0970(one, p->f10);
    }
}
