/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern u8 D_00167BC0[];
extern s32 D_00167240[];
extern s32 D_0016606C;
extern s32 func_00137558(s32 command);
extern s32 func_00126BC0(s32 semaphore);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 send_size, void *receive, s32 receive_size,
                         void (*complete)(void *), void *argument);
s32 func_00138100(s32 *output)
{
    s32 result;
    if (!func_00137558(33))
        return 0;
    if (func_0012A718(D_00167BC0, 33, 0, 0, 0, D_00167240, 8, 0, 0) < 0) {
        func_00126BC0(D_0016606C);
        return 0;
    }
    *output = *(s32 *)(((u32)D_00167240 + 4u) | 0x20000000u);
    result = *(s32 *)((u32)D_00167240 | 0x20000000u);
    func_00126BC0(D_0016606C);
    return result;
}
