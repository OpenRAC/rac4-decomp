/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 data[0x8]; s32 f8; } Type1;
extern void *func_L00_005332F8(void *, s32, u32);
// Clears the trailing word and the first 0x400 bytes.
void *func_L00_00533200(Type1 *p) {
    p->f8 = 0;
    return func_L00_005332F8(p, 0, 0xC);
}
