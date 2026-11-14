/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_003FE6C0(u8 *arg0);
void func_003FD508(u8 *object);
extern void *func_00403308(void *, s32, u32);
void func_003FE500(u8 *a0) {
    func_003FE6C0(a0);
    func_003FD508(a0 + 0x14);
    func_00403308(a0 + 0x28, 0, 8);
}
