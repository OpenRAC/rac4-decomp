/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern s32 func_L00_004FAAF0(void *, s32, s32, void *, s32);
extern void func_L00_0051EB68(s32);
extern void func_L00_005205F8(s32);
extern u8 D_004AD1F0[];
void func_L00_00519050(void *arg0) {
    s32 value;
    if (arg0 != 0) {
        value = func_L00_004FAAF0((u8 *)arg0 + 0x10, -1, 0x17, D_004AD1F0, 0x70);
        if (value <= 0) {
            if (*(s32 *)((u8 *)arg0 + 0xC) != 0) func_L00_0051EB68(*(s32 *)((u8 *)arg0 + 0xC));
            if (*(s32 *)((u8 *)arg0 + 4) != 0) func_L00_005205F8(*(s32 *)((u8 *)arg0 + 4));
            func_004FAD28(arg0);
        }
    }
}
