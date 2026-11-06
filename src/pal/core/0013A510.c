/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Client {
    u8 prefix[0x24];
    u32 remoteServer;
} Client;

extern Client D_001AD900;
extern s32 D_001AD980[];
extern s32 D_001AEEC0[];
extern u8 D_001ADE00[];
extern void func_00129CE0(const void *base, s32 bytes);
extern s32 D_00167C7C[];
extern s32 D_00167C78[];
extern s32 func_00126BF0(s32 semaphore);
extern s32 func_00126BC0(s32 semaphore);
extern void func_0013A460(void *argument);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);

s32 func_0013A510(s32 descriptor, void *buffer, s32 bytes)
{
    if (D_001AD900.remoteServer == 0) {
        return -100;
    }
    if (func_00126BF0(D_00167C7C[0]) < 0) {
        return -200;
    }
    D_001AD980[0] = descriptor;
    D_001AD980[6] = (s32)buffer;
    D_001AD980[3] = bytes;
    D_001AD980[7] = (s32)D_001ADE00;
    func_00129CE0(buffer, bytes);
    func_00129CE0(D_001ADE00, 0xC0);
    if (func_0012A718(&D_001AD900, 5, 1, D_001AD980, 0x30,
                      D_001AEEC0, 4, func_0013A460, D_001ADE00) != 0) {
        func_00126BC0(D_00167C7C[0]);
        return -91;
    }
    D_00167C78[0] = 5;
    return 0;
}
