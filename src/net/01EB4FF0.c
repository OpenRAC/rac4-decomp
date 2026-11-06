/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B26C0[];
extern s32 func_01E9D390(void *);
// Invokes the worker with the fixed address and returns zero.
s32 func_01EB4FF0(void) {
    func_01E9D390(D_001B26C0);
    return 0;
}
