#include "common.h"

extern void func_004D3EF0(void);

s32 D_0021FB84 = 0;

// Advances a three-state counter, calling func_004D3EF0 in the last state.
void func_004D3DC0(void) {
    switch (D_0021FB84) {
    case 0:
        D_0021FB84 = 1;
        return;
    case 1:
        D_0021FB84 = 2;
        break;
    case 2:
        func_004D3EF0();
        break;
    }
}
