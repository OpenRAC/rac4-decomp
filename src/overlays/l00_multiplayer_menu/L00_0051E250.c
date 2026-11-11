/* cflags: @ee29 -O2 -G8 */
#include "common.h"
extern void func_004FAD28(void *);
extern void func_00538B40(s32);
extern void func_L00_00538038(void *);
s32 func_L00_0051E250(void *object) {
    u8 *state = *(u8 **)((u8 *)object + 8);
    if (state == 0) return 0;
    func_L00_00538038(state + 0xC);
    func_L00_00538038(state + 0x20);
    func_L00_00538038(state + 0x34);
    func_L00_00538038(state + 0x48);
    if (*(s32 *)(state + 0x64) != 0) func_00538B40(*(s32 *)(state + 0x64));
    func_004FAD28(state);
    return 0;
}
