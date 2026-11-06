/* cflags: -G0 */
/* cflags: -G0 */
/* C adapted from rac3-decomp func_003B3408 (NTSC-U func_003B3268, commit 403f30a9) */
#include "common.h"

extern void *func_00502150();
extern void func_00502070(void *);
extern u8 D_00223248[];

void func_L00_00621410(void) {
    void *x = D_00223248;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_00502150();
    }
    func_00502070(x);
}
