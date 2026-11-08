#include "common.h"

extern s32 func_L00_005C1050(u8 *s, s32 *pos);
extern void func_L00_005C1618(u8 *, u8 *);

/* from rac3-decomp's func_L39_00595760 */
void func_L00_005C1618(u8 *s, u8 *d) {
    s32 pos = 0;
    s32 n = 0;
    s32 v;
    if (*s != 0) {
        do {
            v = func_L00_005C1050(s, &pos);
            d[n] = v >> 8;
            n++;
            d[n] = v;
            n++;
        } while (s[pos] != 0);
    }
    do {
        d[n++] = 0;
        d[n] = 0;
    } while (0);
}
