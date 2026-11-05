/* cflags: @ee29 -O2 -G8 */
#include "common.h"
extern void func_004FAD28(s32);
extern s32 func_L00_004FAAF0(s32, s32, s32, void *, s32);
extern void func_L00_0051D068(s32);
extern u8 D_004AE1F8[];
void func_L00_0051D000(s32 object) {
    if (object == 0) return;
    if (func_L00_004FAAF0(object + 8, -1, 0xA, D_004AE1F8, 0xF2) > 0) return;
    func_L00_0051D068(object);
    func_004FAD28(object);
}
