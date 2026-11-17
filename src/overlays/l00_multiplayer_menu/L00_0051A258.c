/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);

// Reset the buffers and resize the scratch block to match the source object.
s32 func_L00_0051A258(u8 *arg0) {
    s32 *src;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 4) = 1;
    func_0011A518(arg0 + 0xC, 0, 0x20);
    func_0011A518(arg0 + 0x2C, 0, 0x20);
    func_0011A518(arg0 + 0x4C, 0, 0x20);
    src = *(s32 **)arg0;
    *(s32 *)(arg0 + 0x6C) = 0;
    if (src != 0) {
        if (*(s32 *)(arg0 + 0x74) != src[7]) {
            if (*(void **)(arg0 + 0x78) != 0) {
                func_0011A518(*(void **)(arg0 + 0x78), 0, *(s32 *)(arg0 + 0x74));
                func_004FAD28(*(s32 *)(arg0 + 0x78));
                src = *(s32 **)arg0;
            }
            *(void **)(arg0 + 0x78) = func_L00_004FACD8(src[7]);
            if (*(void **)(arg0 + 0x78) == 0) {
                func_L00_004F84C8(6, 0x6C, 0x21, 0, 0);
                return 0;
            }
            *(s32 *)(arg0 + 0x74) = (*(s32 **)arg0)[7];
        }
    }
    if (*(void **)(arg0 + 0x78) != 0) {
        func_0011A518(*(void **)(arg0 + 0x78), 0, *(s32 *)(arg0 + 0x74));
    }
    *(s32 *)(arg0 + 0x80) = 0;
    *(s64 *)(arg0 + 0x88) = 0;
    return 1;
}
