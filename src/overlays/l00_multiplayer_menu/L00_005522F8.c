/* cflags: @ee29 -O2 -G0 */
#include "common.h"

void func_004FAD28(void *);
void func_L00_005534B0(s32);

void func_L00_005522F8(u8 *arg0) {
    func_L00_005534B0((s32)(arg0 + 8));
    if (*(void **)(arg0 + 0x3C) != 0) {
        func_004FAD28(*(void **)(arg0 + 0x3C));
    }
    if (*(void **)(arg0 + 0x40) != 0) {
        func_004FAD28(*(void **)(arg0 + 0x40));
    }
    if (*(void **)(arg0 + 0x38) != 0) {
        func_004FAD28(*(void **)(arg0 + 0x38));
    }
    if (*(u64 *)(arg0 + 0xE0) & 1) {
        func_004FAD28(arg0);
    }
}
