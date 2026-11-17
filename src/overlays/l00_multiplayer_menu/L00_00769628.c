#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_L00_007698F0(u8 *arg0);
extern s32 func_L00_00769DE0(void *);
extern s32 func_L00_0076A658(void *);
extern s32 func_0076AB38(void *);
extern s32 func_L00_0076B020(void *, s32, s32, s32);
extern s32 func_L00_0076B4E8(void *, u8, s32);
extern s32 func_L00_0076B9D0(void *, u8);

/* Restarts each of the six timed slots whose id is set and whose timer has run out; returns 0 once one was restarted. */
s32 func_L00_00769628(u8 *arg0) {
    s32 r = 1;

    if (arg0[0x3D0] != 0 && arg0[0x3D8] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x3DC) >= 0x3A99) {
        arg0[0x3D8] = 0;
        r = 0;
        func_L00_007698F0(arg0);
    }
    if (arg0[0x408] != 0 && arg0[0x410] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x414) >= 0x3A99) {
        arg0[0x410] = 0;
        r = 0;
        func_L00_00769DE0(arg0);
    }
    if (arg0[0x440] != 0 && arg0[0x448] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x44C) >= 0x3A99) {
        arg0[0x448] = 0;
        r = 0;
        func_L00_0076A658(arg0);
    }
    if (arg0[0x478] != 0 && arg0[0x480] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x484) >= 0x3A99) {
        arg0[0x480] = 0;
        r = 0;
        func_0076AB38(arg0);
    }
    if (arg0[0x4B8] != 0 && arg0[0x4C0] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x4C4) >= 0x3A99) {
        arg0[0x4C0] = 0;
        r = 0;
        func_L00_0076B020(arg0, *(s32 *)(arg0 + 0x4B0), *(s32 *)(arg0 + 0x4B4), 1);
    }
    if (arg0[0x4F8] != 0 && arg0[0x500] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x504) >= 0x3A99) {
        arg0[0x500] = 0;
        r = 0;
        func_L00_0076B4E8(arg0, arg0[0x4F0], *(s32 *)(arg0 + 0x4F4));
    }
    if (arg0[0x531] != 0 && arg0[0x538] != 0 && (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x53C) >= 0x3A99) {
        arg0[0x538] = 0;
        r = 0;
        func_L00_0076B9D0(arg0, arg0[0x530]);
    }
    return r;
}
