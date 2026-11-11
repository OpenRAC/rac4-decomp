#include "common.h"

extern void func_00453718();
extern u32 func_0048B818(s32 arg0, u32 *arg1, u32 arg2);

extern char *D_002214D8;

/* Reads a count, allocates count words from a bump allocator and copies them in. */
s32 func_0048BEC0(u8 *arg0, u32 *arg1, u32 arg2) {
    s32 count;
    s32 i;

    func_00453718(&count, arg0, 4);
    arg0 += 4;
    *(char **)(D_002214D8 + 0x3008) = (char *)func_0048B818(count * 4, arg1, arg2);
    if (*(char **)(D_002214D8 + 0x3008) == 0) {
        return 1;
    }
    for (i = 0; i < count; i++) {
        func_00453718(*(char **)(D_002214D8 + 0x3008) + i * 4, arg0, 4);
        arg0 += 4;
    }
    return 0;
}
