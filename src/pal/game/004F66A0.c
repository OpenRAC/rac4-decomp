#include "common.h"
typedef struct State {
    u16 kind;
    s16 count;
    u8 pad[0x10];
    s32 last;
} State;
extern State D_001DFCC0;
extern s32 D_00222040;
extern s32 func_00453CE8(s32 *);
extern void func_004F60A8(s32, s32, s32, s32);
s32 func_004F66A0(s32 unused)
{
    s32 done = func_00453CE8(&D_00222040) != 0;
    func_004F60A8(D_001DFCC0.count, 250, 12, 12);
    return done;
}
