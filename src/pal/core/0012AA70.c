/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);
extern s32 func_00127A08(s32 microseconds);

s32 func_0012AA70(void *client, s32 command, u32 mode, const void *send, s32 sendSize, void *receive, s32 receiveSize, void (*complete)(void *), void *argument, s32 failFast)
{
    s32 failed = 0;
    s32 delay = 1;
    s32 attempt = 0;

    do {
        failed = (u32)func_0012A718(client, command, mode, send, sendSize,
                                    receive, receiveSize, complete, argument) >>
                 31;
        if (!failed || failFast) {
            break;
        }
        func_00127A08(delay * 1000);
        if (delay < 127) {
            delay *= 2;
        }
        attempt++;
    } while (attempt < 101);
    return failed;
}
