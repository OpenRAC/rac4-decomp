/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
extern s32 func_00126F60(void *, s32);

typedef struct {
    void *f0;
    u32 f4;
    s32 f8;
    s32 fC;
} Type2;

s32 func_01E9B700(u8 *arg0) {
    Type2 buf;
    s32 sz;
    if (--*(s32 *)(arg0 + 4) == 0) {
        sz = 0x10;
        *(s32 *)*(u32 **)(arg0 + 0x30) = *(s32 *)(arg0 + 0x1C) - *(s32 *)(arg0 + 0x28);
        func_0011A518(&buf, 0, 0x10);
        buf.f0 = *(void **)(arg0 + 0x30);
        buf.f8 = sz;
        buf.f4 = *(u32 *)(arg0 + 0x40);
        func_00126F60(&buf, 1);
    }
    return 0;
}
