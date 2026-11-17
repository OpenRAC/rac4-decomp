#include "common.h"

extern s32 D_0021E824;
extern s32 D_0021E828;
extern s16 D_24AD4C[];
extern s32 D_0021DDB8;
extern s32 func_L00_005E60A0(s32);
extern void *func_L00_005F2FB8(void);

// Every other tick, when no global blocks it, picks a direction from the input flags, latches it in the linked block (+0x824) and records D_0021DDB8.
void func_L01_0050BC88(void *arg0) {
    u8 *linked = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 *state = func_L00_005F2FB8();
    s32 dir;
    s32 id;
    s32 stamp;

    if (D_0021E824 == 0 && D_0021E828 == 0 && state[3] != 0 && D_24AD4C[0] == 0) {
        if (++*(s32 *)(linked + 0x814) & 1) {
            dir = -1;
            if (*(u32 *)(state + 0x1E0) & 1) {
                dir = 1;
            } else if (*(u32 *)(state + 0x1E4) & 1) {
                dir = 0;
            } else if (state[3] != 0) {
                dir = *(s32 *)(linked + 0x824) ^ 1;
            }
            id = -1;
            if (dir == 0) {
                id = (func_L00_005E60A0(2) != 0) ? 0x28A0 : 0x289D;
            } else if (dir == 1) {
                id = 0x28A2;
            }
            if (id >= 0) {
                *(s32 *)(state + 0x18) = D_0021DDB8;
                stamp = D_0021DDB8;
                *(s32 *)(linked + 0x824) = dir;
                *(s32 *)(linked + 0x810) = stamp;
            }
        }
    }
}
