#include "common.h"

extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D8CC0)(void);
extern s32 (*D_001D8CB8)();
extern void (*D_001D8CBC)(s32);
extern void (*D_001D8CC4)(void);
extern void func_0038A140(void (*)(), s32);
void func_003BE6C0(void (*cb)(u32));
extern s16 D_001DFC42[];
extern s32 func_004534D0(s32 *);
void func_004F5028(s16, s32, s32, s32);
extern u8 D_00221F40;

/* from rac3-decomp's func_003BE7A8, constants adapted */
s32 func_004F5620(void) {
    s32 temp_s0;
    temp_s0 = func_004534D0(&D_00221F40) != 0;
    func_004F5028(D_001DFC42[0], 0x12c, 0xf, 0xf);
    return temp_s0;
}
