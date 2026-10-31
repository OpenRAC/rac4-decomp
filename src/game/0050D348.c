#include "common.h"

extern s32 func_0050BFA8(void *, void *);

// Asks arg1's vtable slot 0x14 (arg1 and 1); when it accepts, runs func_0050BFA8 and copies 8 bytes at 0x40 from arg1 to arg0, returning 1; otherwise returns 0.
s32 func_0050D348(void *arg0, void *arg1) {
    typedef struct {
        u64 v;
    } __attribute__((packed)) u64p;
    void *vt;
    s32 (*fn)(void *, s32);

    vt = *(void **)((u8 *)arg1 + 8);
    fn = *(s32 (**)(void *, s32))((u8 *)vt + 0x14);
    if (fn(arg1, 1) != 0) {
        func_0050BFA8(arg0, arg1);
        *(u64p *)((u8 *)arg0 + 0x40) = *(u64p *)((u8 *)arg1 + 0x40);
        return 1;
    }
    return 0;
}
