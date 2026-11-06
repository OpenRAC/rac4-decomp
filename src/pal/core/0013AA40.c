/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Client {
    u8 prefix[0x24];
    u32 remoteServer;
} Client;

typedef struct Request {
    s32 port;
    s32 slot;
    s32 mode;
    s32 count;
    void *buffer;
    char path[0x400];
} Request;

extern Client D_001AD900;
extern Request D_001AD9B0;
extern s32 D_001AEEC0[];
extern s32 D_00167C7C[];
extern s32 D_00167C78[];
extern s32 func_00126BF0(s32 semaphore);
extern s32 func_00126BC0(s32 semaphore);
extern char *func_0011AFC8(char *destination, const char *source, u32 length);
extern void func_00129CE0(const void *base, s32 bytes);
extern void func_0013A148(void *argument);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);

s32 func_0013AA40(s32 port, s32 slot, const char *path, s32 mode, s32 count, void *buffer)
{
    if (D_001AD900.remoteServer == 0) {
        return -100;
    }
    if (func_00126BF0(D_00167C7C[0]) < 0) {
        return -200;
    }
    if (path == 0 || path[0] == 0) {
        func_00126BC0(D_00167C7C[0]);
        return -210;
    }
    D_001AD9B0.port = port;
    D_001AD9B0.slot = slot;
    D_001AD9B0.mode = mode;
    D_001AD9B0.count = count;
    D_001AD9B0.buffer = buffer;
    func_0011AFC8(D_001AD9B0.path, path, 0x3FF);
    D_001AD9B0.path[0x3FF] = 0;
    if (count >= 0) {
        func_00129CE0(buffer, (s32)((u32)count << 6));
    }
    if (func_0012A718(&D_001AD900, 13, 1, &D_001AD9B0, 0x414,
                      D_001AEEC0, 4, func_0013A148, 0) != 0) {
        func_00126BC0(D_00167C7C[0]);
        return -91;
    }
    D_00167C78[0] = 13;
    return 0;
}
