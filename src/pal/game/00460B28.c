#include "common.h"

typedef struct NetworkState {
    s32 mode;
    u8 unknown4[0x260];
    u8 enabled;
} NetworkState;

extern NetworkState D_001721E0;
extern s32 func_01E9A4A0(void);

s32 func_00460B28(void)
{
    D_001721E0.mode = 2;
    if (D_001721E0.enabled) {
        func_01E9A4A0();
    }
    return 1;
}
