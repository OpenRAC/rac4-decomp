#include "common.h"

typedef struct NetworkState {
    s32 mode;
    u8 unknown4[0x260];
    u8 enabled;
} NetworkState;

extern NetworkState D_00172160;
extern s32 func_01E9A4A0(void);

s32 func_004602E8(void)
{
    D_00172160.mode = 2;
    if (D_00172160.enabled) {
        func_01E9A4A0();
    }
    return 1;
}
