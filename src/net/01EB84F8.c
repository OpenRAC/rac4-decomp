/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
extern u16 func_01EB8E98(s32 arg0, s32 arg1);
extern void func_01EB9880(void *, s32 *, u16 *);
extern s32 func_01EBAEE0(void *, s32, s32, u16, IovList *);

// Stores arg2 in slot arg1 of arg0's table, sends that slot, and returns a status code.
s32 func_01EB84F8(u8 *arg0, s32 arg1, u32 arg2) {
    struct { u16 f0; u8 f2; u32 f4; } msg;
    IovList l;
    u16 sp60;
    s32 sp64;
    u8 idx;

    idx = arg1;
    sp60 = 0xFFFE;
    sp64 = 0;
    if (arg0 == NULL) {
        return 2;
    }
    if (idx >= *(u32 *)(arg0 + 0x1D8)) {
        return 2;
    }
    if (*(u8 **)(arg0 + 0x188) == NULL) {
        return 3;
    }
    func_01EB9880(arg0, &sp64, &sp60);
    if (sp64 != 9) {
        return 0xD4ED;
    }
    if (arg2 < 2) {
        *(u32 *)(*(u8 **)(arg0 + 0x188) + idx * 0x18 + 0x14) = arg2;
        msg.f0 = func_01EB8E98(5, 8);
        msg.f2 = idx;
        msg.f4 = arg2;
        l.count = 0;
        l.total = 0;
        l.v[l.count].p = &msg;
        l.v[l.count].n = 8;
        l.total += 8;
        l.count++;
        return func_01EBAEE0(arg0, 0, 0, 0xF000, &l);
    }
    return 2;
}
