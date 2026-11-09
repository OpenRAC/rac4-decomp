#include "common.h"

extern void func_00453718();
extern u32 func_0048B818(s32 arg0, u32 *arg1, u32 arg2);
extern char *D_002214D8;

/* Reads a count from arg0, allocates count words via func_0048B818 into D_002214D8+0x3004, then copies count words after it; returns 1 when allocation fails. */
s32 func_0048BDF0(s32 arg0, u32 *arg1, u32 arg2) {
    s32 count;
    s32 i;

    func_00453718(&count, arg0, 4);
    arg0 += 4;
    *(u32 *)(D_002214D8 + 0x3004) = func_0048B818(count * 4, arg1, arg2);
    if (*(u32 *)(D_002214D8 + 0x3004) == 0) {
        return 1;
    }
    for (i = 0; i < count; i++) {
        func_00453718(*(s32 *)(D_002214D8 + 0x3004) + i * 4, arg0, 4);
        arg0 += 4;
    }
    return 0;
}
