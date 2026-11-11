/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_001A9500[];
extern u8 D_001A9700[];
extern s32 func_0012C4B8(void);
extern s32 func_0012C5B8(void);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);

s32 func_0012CA90(s32 descriptor)
{
    if (func_0012C4B8() < 0) {
        return (s32)0xFFFF0000u;
    }
    if (func_0012C5B8()) {
        return (s32)0xFFFEFFFCu;
    }
    D_001A9500[0] = descriptor;
    if (func_0012A718(D_001A9700, 8, 0, D_001A9500, 4,
                      D_001A9500, 4, 0, 0) < 0) {
        return (s32)0xFFFEFFFFu;
    }
    return D_001A9500[0];
}
