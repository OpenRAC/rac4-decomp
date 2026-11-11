#include "common.h"

typedef struct Stream {
    u8 prefix[0x48];
    u8 ring[0x60];
    s32 state;
} Stream;
typedef struct {
    u8 bytes[4];
} Command;
extern Command D_00220918[];
extern Stream *D_00221ED4;
extern void func_004F1C10(Stream *, u8 **, s32 *, u8 **, s32 *);
extern s32 func_004F2138(u8 *, s32, u8 *, s32, const void *, s32, const void *, s32);
extern void func_004F1C30(Stream *, s32);
extern void func_004F16C0(void *);
s32 func_004F1D20(Stream *stream)
{
    Command command = D_00220918[0];
    u8 *first;
    s32 firstSize;
    u8 *second;
    s32 secondSize;
    s32 copied;
    func_004F1C10(stream, &first, &firstSize, &second, &secondSize);
    if (firstSize + secondSize < 4)
        return 0;
    copied = func_004F2138((u8 *)(((u32)first & 0x0FFFFFFF) | 0x20000000), firstSize,
                           (u8 *)(((u32)second & 0x0FFFFFFF) | 0x20000000), secondSize, &command, 4, 0, 0);
    func_004F1C30(D_00221ED4, copied);
    func_004F16C0(stream->ring);
    if (stream->state == 0)
        stream->state = 2;
    return 1;
}
