#include "common.h"

typedef struct { u8 pad[0x618]; u8 f618; u8 pad2[3]; u8 *f61C; s32 f620; } Type0;
extern Type0 D_00172160;
typedef struct { u8 d[0x190]; } Type1;

// Copies the 0x190-byte block at arg0 + 0x20 to the buffer at D_00172160.f61C, then stores arg0's word at 0x18 to f620.
void func_0015C018(u8 *arg0) {
    D_00172160.f618 = 0;
    *(Type1 *)D_00172160.f61C = *(Type1 *)(arg0 + 0x20);
    D_00172160.f620 = *(s32 *)(arg0 + 0x18);
}
