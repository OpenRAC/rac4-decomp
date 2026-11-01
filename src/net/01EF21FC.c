/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 data[0x400]; s32 f400; } Type1;
extern void *func_0011A518(void *, s32, u32);
// Clears the trailing word and the first 0x400 bytes.
void *func_01EF21FC(Type1 *p) {
    p->f400 = 0;
    return func_0011A518(p, 0, 0x400);
}
