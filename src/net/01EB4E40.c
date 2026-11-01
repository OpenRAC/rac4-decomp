/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
extern void func_01EA91C0(u8 *, u32);
// Formats the first word into the supplied buffer and returns zero.
s32 func_01EB4E40(u8 *buffer, Type1 value) {
    func_01EA91C0(buffer, value.f0);
    return 0;
}
