#include "common.h"

extern char D_306D20[];
extern char D_003D8DE0[];

/* Runs the callbacks of an entry's enabled slots once, then records the flags. */
void func_0049A760(s32 arg0)
{
    u8 *e;
    u8 *cb;
    s32 i;
    void (*fn)(s32);

    e = D_306D20 + arg0 * 16;
    if (e[0] == 0) {
        e[0] = 1;
        cb = D_003D8DE0;
        i = 0;
        do {
            if ((*(s32 *)(e + 4) >> i) & 1) {
                fn = *(void (**)(s32))(cb + 4);
                if (fn != NULL) {
                    fn(arg0);
                }
            }
            i++;
            cb += 12;
        } while (i < 11);
        *(s32 *)(e + 0xC) = 0;
        *(s32 *)(e + 8) = *(s32 *)(e + 4);
    }
}
