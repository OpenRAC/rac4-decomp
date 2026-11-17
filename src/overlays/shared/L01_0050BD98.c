#include "common.h"

extern s32 D_0021E824;
extern s32 D_0021E828;
extern s32 D_0021DDB8;
extern s16 D_24AD4C[];
extern void *func_L00_005F2FB8(void);

// Every other tick, when no global blocks it, picks a direction (-1/0/1) from the input flags and, if one applies, latches it in the linked block.
void func_L01_0050BD98(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    u8 *state = func_L00_005F2FB8();
    s32 counter;
    s32 dir;
    s32 id;

    if (D_0021E824 == 0 && D_0021E828 == 0 && state[3] != 0 && D_24AD4C[0] == 0) {
        counter = *(s32 *)(linked + 0x818) + 1;
        *(s32 *)(linked + 0x818) = counter;
        if (counter & 1) {
            dir = -1;
            if (*(u32 *)(state + 0x1E0) & 1) {
                dir = 1;
            } else if (*(u32 *)(state + 0x1E4) & 1) {
                dir = 0;
            } else if (state[3] != 0) {
                dir = *(s32 *)(linked + 0x828) ^ 1;
            }
            id = -1;
            if (dir == 0) {
                id = 0x289F;
            } else if (dir == 1) {
                id = 0x28A4;
            }
            if (id >= 0) {
                *(s32 *)(state + 0x18) = D_0021DDB8;
                *(s32 *)(linked + 0x810) = D_0021DDB8;
                *(s32 *)(linked + 0x828) = dir;
            }
        }
    }
}
