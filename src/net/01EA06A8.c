/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EA95C0(s32 *);
void func_01EA06A8(s32 *arg0) {
    if (*arg0 != 0) {
        func_01EA95C0(arg0);
    }
}
