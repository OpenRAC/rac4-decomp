#include "common.h"

extern void func_0047F768(s32 arg0, s32 arg1);
extern void func_004D3EF0(void);
extern void (*D_002219EC)(void);

s32 D_0021FB84 = 0;

void func_004D3908(void) {
    s32 v1 = D_0021FB84;

    switch (v1) {
    case 0:
        if (D_002219EC != 0) {
            D_002219EC();
            D_002219EC = 0;
        }
        func_0047F768(0, 0);
        v1 = D_0021FB84;
        v1 = v1 + 1;
        D_0021FB84 = v1;
        break;
    case 1:
        D_0021FB84 = 2;
        break;
    case 2:
        func_004D3EF0();
        break;
    }
}
