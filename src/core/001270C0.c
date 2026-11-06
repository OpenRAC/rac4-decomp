/* cflags: @ee29 -O2 -G0 */
/* libgraph: 2.9-ee-991111, @ee29 -O2 -G0. The library's sceGsSyncV: waits for the next vertical
 * blank (INTC_STAT bit 2, or the flag func_00126F10 sets from the vblank handler) and returns the
 * GS CSR value that handler stored. */
#include "common.h"

extern void func_00126F10(volatile s32 *flag, volatile long *csr);
extern s32 func_0012D420();
extern s32 func_0012D470();

long func_001270C0(void) {
    volatile s32 flag;
    volatile long csr;
    s32 s;

    flag = 0;
    func_00126F10(&flag, &csr);
    s = func_0012D420();
    *(volatile u32 *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s != 0) {
        func_0012D470();
    }
    while (!(*(volatile u32 *)0x1000F000 & 4) && flag == 0) {
    }
    s = func_0012D420();
    *(volatile u32 *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s != 0) {
        func_0012D470();
    }
    return csr;
}
