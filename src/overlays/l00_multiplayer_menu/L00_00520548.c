/* cflags: @ee29 */
#include "common.h"

extern s32 func_004FAD28(void *);

void func_L00_00520548(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x14) & 2) {
        void *p = *(void **)(arg0 + 0xC);
        if (p != NULL) {
            func_004FAD28(p);
        }
    }
    if (*(s32 *)(arg0 + 0x14) & 1) {
        func_004FAD28(arg0);
    }
}
