#include "common.h"

extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern s32 D_0021DE40;
extern s16 D_0024AE4C[];
extern void *func_0047DE20(void);

// Every other tick, when no global blocks it, picks a direction (-1/0/1) from the input flags and, if one applies, latches it in the linked block.
void func_L01_0050E110(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    u8 *state = func_0047DE20();
    s32 counter;
    s32 dir;
    s32 id;

    if (D_0021E8A4 == 0 && D_0021E8A8 == 0 && state[3] != 0 && D_0024AE4C[0] == 0) {
        counter = *(s32 *)(linked + 2080) + 1;
        *(s32 *)(linked + 2080) = counter;
        if (counter & 1) {
            dir = -1;
            if (*(u32 *)(state + 0x1E0) & 1) {
                dir = 1;
            } else if (*(u32 *)(state + 0x1E4) & 1) {
                dir = 0;
            } else if (state[3] != 0) {
                dir = *(s32 *)(linked + 2096) ^ 1;
            }
            id = -1;
            if (dir == 0) {
                id = 10398;
            } else if (dir == 1) {
                id = 10403;
            }
            if (id >= 0) {
                *(s32 *)(state + 0x18) = D_0021DE40;
                *(s32 *)(linked + 0x810) = D_0021DE40;
                *(s32 *)(linked + 2096) = dir;
            }
        }
    }
}
