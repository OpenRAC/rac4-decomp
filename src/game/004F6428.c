#include "common.h"

extern void func_00436C50(void);
extern void func_004F3898(s32 a);
extern u8 D_1DFC40[];

/* Sets the 16-bit flag at offset 0xA of D_1DFC40 around a call to func_00436C50, then calls func_004F3898 with arg0. */
void func_004F6428(s32 arg0) {
    s16 *p = (s16 *)D_1DFC40;

    p[5] = 1;
    func_00436C50();
    p[5] = 0;
    func_004F3898(arg0);
}
