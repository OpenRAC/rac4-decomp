#include "common.h"

typedef struct { u8 f0; u8 pad[0x41F]; } Slot;
typedef struct { u8 pad0[0x8D8]; Slot s[3]; } S;
typedef struct { s32 w[7]; } Head;
typedef struct { s32 w[0x100]; } Body;

extern S D_00172160[];
extern u8 D_00172A3C[];

// Copies the record at arg0 into the first free slot of the table and marks that slot used.
void func_0015C828(u8 *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_00172160->s[i].f0 == 0) {
            break;
        }
    }
    if (i < 3) {
        *(Head *)(D_00172A3C + i * 0x420) = *(Head *)(arg0 + 4);
        *(Body *)(D_00172A3C + 0x1C + i * 0x420) = *(Body *)(arg0 + 0x20);
        ((S *)((u8 *)D_00172160 + i * 0x420))->s[0].f0 = 1;
    }
}
