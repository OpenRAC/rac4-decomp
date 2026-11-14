#include "common.h"

extern u8 *D_002233A4;

typedef struct { u8 b[0x1A0]; } Blob1;

/* Copies a 0x1A0-byte block into the state and sets two flag bytes. */
void func_L00_0076F6C0(Blob1 *arg0) {
    u8 *p = *(u8 **)(D_002233A4 + 0x48);
    *(Blob1 *)(p + 0x284) = *arg0;
    p[0x10] = 0;
    p[3] = 1;
}
