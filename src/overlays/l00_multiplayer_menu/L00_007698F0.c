#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED54A8();
extern int D_002217E0[];
extern char func_0015CE80[];

// Start a request when the slot is active and its id is set; returns 0 if the id is -1.
s32 func_L00_007698F0(u8 *arg0) {
    s32 buf[9];
    s32 r = 1;
    if (arg0[0x3D0] != 0) {
        if (*(s32 *)arg0 == -1) {
            return 0;
        }
        buf[6] = *(s32 *)arg0;
        *(u16 *)buf = *(u16 *)D_002217E0;
        arg0[0x3D8] = 1;
        buf[7] = 0;
        buf[8] = 0;
        *(s32 *)(arg0 + 0x3DC) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED54A8(buf, func_0015CE80, 0));
        if (func_0015B558() != 0) {
            r = 0;
        }
    }
    return r;
}
