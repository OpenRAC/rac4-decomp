/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 serve;
} Cd_13AEF8;
extern void func_00129D90(s32);
extern s32 func_0012A538(void *, s32, s32);
extern void func_001294F0();
extern void func_0013AE70();
extern s32 func_0013AE98();
extern s32 func_0013B168(void);
extern void *func_0011A518();
extern Cd_13AEF8 D_001AEE80;
extern u8 D_001AEF40[];
extern char D_00194F50[];
extern char D_00194F68[];
extern char D_00194F90[];

/* from rac3-decomp's func_0012EA38 */
int func_0013AEF8(void)
{
    int i;
    int ver;
    func_00129D90(0);
    for (;;) {
        if (func_0012A538(&D_001AEE80, 0x80000900, 0) < 0) {
            func_0013AE70(D_00194F50);
            return 0;
        }
        if (D_001AEE80.serve != 0) {
            break;
        }
        i = 0x10000;
        while (i--) {
        }
    }
    ver = func_0013B168();
    if ((ver >> 4) != 0x31) {
        func_001294F0(D_00194F68);
        func_001294F0(D_00194F90, 3, 0x10, ver >> 8, ver & 0xFF);
        return 0;
    }
    func_0011A518(D_001AEF40, 0, 0x80);
    func_0013AE98(D_001AEF40);
    return 1;
}
