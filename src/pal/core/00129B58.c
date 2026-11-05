/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_001299E0(u32 command, u32 mode, void *packet, s32 packetSize,
                         const void *extra, u32 remoteAddress, s32 extraSize);

s32 func_00129B58(u32 command, void *packet, s32 packetSize, const void *extra, u32 remoteAddress, s32 extraSize)
{
    return func_001299E0(command, 1, packet, packetSize,
                         extra, remoteAddress, extraSize);
}
