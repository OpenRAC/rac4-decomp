#include "common.h"

extern void func_L00_005C0E28(void);
extern s32 func_005BD768(u8 *p, s32 off, s32 *out);
extern s32 func_L00_005C1290(s32 v);
extern void func_L00_005C1428(u8 *, u8 *);

/* from rac3-decomp's func_L39_00595570 */
void func_L00_005C1428(u8 *src, u8 *dst) {
    s32 tmp = 0;
    s32 i = 0;
    s32 o = 0;
    s32 r;
    func_L00_005C0E28();
    if (src[0] != 0) {
        do {
            i += func_005BD768(src, i, &tmp);
            i++;
            r = func_L00_005C1290(tmp);
            dst[o] = r >> 8;
            o++;
            dst[o] = r;
            o++;
        } while (src[i] != 0);
    }
    dst[o] = 0;
    o++;
    dst[o] = 0;
}
