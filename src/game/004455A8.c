#include "common.h"

extern void func_004E7830(s32);
extern void func_004E7520(void);
extern void func_004E7638(void);
extern void func_004494E8(s32, s32);
extern s32 D_002211D0;
extern s32 D_0021DA34;
extern s32 D_00235958[];

/* Calls func_004E7830(1), func_004E7520 and func_004E7638, clears D_002211D0, copies D_00235958 to D_0021DA34 and calls func_004494E8(30, 0). */
void func_004455A8(void) {
    func_004E7830(1);
    func_004E7520();
    func_004E7638();
    D_002211D0 = 0;
    D_0021DA34 = D_00235958[0];
    func_004494E8(0x1E, 0);
}
