/* cflags: @ee29 */
#include "common.h"

extern void func_004FAD28(void *);
extern void func_L00_00520548(u8 *);

void func_L00_005205F8(u8 *arg0) {
    s32 i;
    void *p;

    for (i = 0; i < *(s32 *)(arg0 + 4); i++)
        func_L00_00520548(*(u8 **)(*(s32 *)(arg0 + 0xC) + i * 4));

    p = *(void **)(arg0 + 0xC);
    if (p != NULL) {
        func_004FAD28(p);
        *(s32 *)(arg0 + 0xC) = 0;
    }
    p = *(void **)(arg0 + 0x10);
    if (p != NULL) {
        func_004FAD28(p);
    }
    if (*(s32 *)(arg0 + 0x14) & 1) {
        func_004FAD28(arg0);
    }
}
