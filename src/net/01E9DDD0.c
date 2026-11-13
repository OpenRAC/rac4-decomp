/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; char _p10[0x4C]; s32 f5C; s32 f60; } Type1;
extern void func_0011A518(void *, s32, s32);
extern void func_01EAB690(s32 *);
extern s32 func_01EA9988(s32);
s32 func_01E9DDD0(Type1 *arg0) {
    s32 buf[12];
    if (arg0 == NULL) {
        return 0x17;
    }
    func_0011A518(arg0, 0, 0x6C);
    func_01EAB690(buf);
    func_01EA9988(buf[8]);
    arg0->f0 = 1;
    arg0->f8 = 1;
    arg0->f60 = 0;
    arg0->f5C = 0;
    arg0->f4 = 0;
    arg0->fC = -1;
    return 0;
}
