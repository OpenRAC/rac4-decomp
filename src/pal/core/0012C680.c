/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct ArgumentBlock {
    u8 bytes[0xFC];
} ArgumentBlock;

typedef struct Request {
    u32 imageAddress;
    s32 argumentBytes;
    u8 unknown8[0xFC];
    ArgumentBlock arguments;
} Request;

extern Request D_001A9580[];
extern u8 D_001A9780[];
extern s32 func_0012C4B8(void);
extern s32 func_0012C5B8(void);
extern void *func_0011A370(void *destination, const void *source, u32 bytes);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendBytes,
                         void *receive, s32 receiveBytes,
                         void (*complete)(void *), void *userdata);

s32 func_0012C680(u32 imageAddress, s32 argumentBytes, const ArgumentBlock *arguments, s32 *moduleStatus)
{
    if (func_0012C4B8() < 0) {
        return (s32)0xFFFF0000u;
    }
    if (func_0012C5B8() != 0) {
        return (s32)0xFFFEFFFCu;
    }

    D_001A9580[0].imageAddress = imageAddress;
    if (arguments != 0) {
        if (argumentBytes >= 0xFD) {
            D_001A9580[0].arguments = *arguments;
            D_001A9580[0].argumentBytes = 0xFC;
        } else {
            func_0011A370(&D_001A9580[0].arguments, arguments, argumentBytes);
            D_001A9580[0].argumentBytes = argumentBytes;
        }
    } else {
        D_001A9580[0].argumentBytes = 0;
    }

    if (func_0012A718(D_001A9780, 6, 0, D_001A9580, 0x200,
                      D_001A9580, 8, 0, 0) < 0) {
        return (s32)0xFFFEFFFFu;
    }
    {
        s32 status = D_001A9580[0].argumentBytes;
        s32 result = D_001A9580[0].imageAddress;
        *moduleStatus = status;
        return result;
    }
}
