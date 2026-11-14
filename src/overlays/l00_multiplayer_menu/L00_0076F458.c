#include "common.h"

extern u8 *D_002233A4;
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);

typedef struct { u8 b[0x1A0]; } Blob1;

/* Copies a 0x1A0-byte block into the state and records a timer value. */
void func_L00_0076F458(Blob1 *arg0) {
    u8 *p = *(u8 **)(D_002233A4 + 0x48);
    p[4] = 0;
    *(Blob1 *)(p + 0xE4) = *arg0;
    *(s32 *)(p + 0xC) = func_0012FEB0(func_0012E370(), 0x24000);
    p[3] = 1;
}
