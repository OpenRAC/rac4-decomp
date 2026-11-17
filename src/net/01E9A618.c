/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00127438(void *, void *);
extern void func_001294F0(char *fmt, ...);
extern s32 func_0012A718();
extern s32 func_01E9A9A8(s32 arg0);
extern char D_001941B0[];
extern char D_00194200[];
extern char D_00194218[];
extern char D_00194268[];
extern char D_00194290[];
extern s32 D_1AD200;
extern char D_1AD380[];
extern s32 D_1AD3AC;

/* Starts the transfer for the block at arg0, reporting an error when the link is not ready or arg0 is not aligned. */
s32 func_01E9A618(s32 arg0) {
    s32 *var_s1;
    s32 temp_s0;
    s32 temp_v0;

    var_s1 = &D_1AD200;
    if (D_1AD3AC == 0) {
        func_001294F0(D_001941B0, D_00194200);
        func_001294F0(D_00194218);
        return -1;
    }
    if (arg0 & 0x3F) {
        func_001294F0(D_001941B0, D_00194200);
        func_001294F0(D_00194268, arg0, 0x40);
        return -0x16;
    }
    func_00127438((void *)arg0, (void *)(arg0 + 0x133F));
    *var_s1 = arg0;
    func_0012A718(D_1AD380, 1, 0, var_s1, 4, var_s1, 4, 0, 0);
    temp_s0 = *var_s1;
    func_001294F0(D_001941B0, D_00194200);
    func_001294F0(D_00194290, temp_s0);
    do {
        temp_v0 = func_01E9A9A8(0x7D0);
    } while (temp_v0 >= 2);
    return temp_v0;
}
