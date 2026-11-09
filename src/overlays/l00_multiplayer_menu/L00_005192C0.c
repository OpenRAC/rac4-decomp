/* cflags: @ee29 */
#include "common.h"

extern void func_L00_0051EBD0(s32, s32, s32, s32, s32);
extern s32 func_L00_0051ED40(s32, s32);

s32 func_L00_005192C0(u8 *arg0) {
    s32 flags = *(s32 *)(arg0 + 0x14);
    if (!(flags & 0x100)) {
        *(s32 *)(arg0 + 0x14) = flags | 0x100;
        func_L00_0051EBD0(*(s32 *)(arg0 + 0xC), *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 4), 0, 0);
    }
    return func_L00_0051ED40(*(s32 *)(arg0 + 0xC), 0) == 0;
}
