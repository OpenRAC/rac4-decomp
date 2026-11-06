/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Client {
    u8 prefix[0x24];
    u32 remoteServer;
} Client;

extern Client D_001AD900;
extern s32 D_001AD980[];
extern s32 D_001AEEC0[];
extern s32 D_00167C7C[];
extern s32 D_00167C78[];
extern s32 func_00126BF0(s32 semaphore);
extern s32 func_00126BC0(s32 semaphore);
extern void func_0013A148(void *argument);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);

s32 func_0013A380(s32 descriptor, s32 offset, s32 origin)
{
    if (D_001AD900.remoteServer == 0) {
        return -100;
    }
    if (func_00126BF0(D_00167C7C[0]) < 0) {
        return -200;
    }
    D_001AD980[0] = descriptor;
    D_001AD980[4] = offset;
    D_001AD980[5] = origin;
    if (func_0012A718(&D_001AD900, 4, 1, D_001AD980, 0x30,
                      D_001AEEC0, 4, func_0013A148, 0) != 0) {
        func_00126BC0(D_00167C7C[0]);
        return -91;
    }
    D_00167C78[0] = 4;
    return 0;
}
