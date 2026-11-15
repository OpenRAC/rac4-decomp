#include "common.h"

typedef struct Type1 { void (*fn)(void); s32 f4; s32 f8; s32 fC; } Type1;
extern u8 D_0021EE18;
extern Type1 D_003D8E68[];
extern u8 D_306DC0[];
extern u8 D_2215A0[8];
extern void func_00453608(void *p, s32 v, s32 n);

// Clear two tables, set per-entry values in D_306DC0 by D_0021EE18, then call every registered init function.
void func_0049AA88(void)
{
    u8 *p;
    s32 k;
    s32 i;
    void (*fn)(void);

    func_00453608(D_306DC0, 0, 0xF0);
    func_00453608(D_2215A0, 0, 8);
    k = 3;
    p = D_306DC0 + 8;
    do {
        k -= 1;
        if (D_0021EE18 != 0) {
            *(s32 *)(p - 4) = 0x20;
            *(s32 *)p = 0x20;
        } else {
            *(s32 *)(p - 4) = 1;
            *(s32 *)p = 1;
        }
        p += 0x3C;
    } while (k >= 0);
    i = 0;
    while (i < 37) {
        fn = D_003D8E68[i++].fn;
        if (fn != 0) {
            fn();
        }
    }
}
