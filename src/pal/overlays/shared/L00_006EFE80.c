#include "common.h"

typedef void (*Fn_6600D8)(void *, void *);
extern void func_L00_006EFE80(s32 *p);
extern void func_00453E20(void *, s32, s32);

/* PAL: from rac3-decomp's func_L39_00662A48 */
void func_L00_006EFE80(s32 *p) {
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    func_00453E20(&p[3], 0xCDCDCDCD, 64);
    p[19] = 0;
    ((u8 *)p)[84] = 0;
    p[20] = -1;
    ((u8 *)p)[85] = 0;
}
