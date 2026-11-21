#include "common.h"

typedef struct { s32 w[7]; } Head;
typedef struct { s32 w[0x100]; } Body;
typedef struct { u8 f0; u8 pad[3]; Head h; Body b; } Slot;
typedef struct { u8 pad0[0x8D8]; Slot s[3]; } S;

extern void func_0011A518(void *, s32, s32);
extern S D_00172160[];
extern u8 D_0017327C[];

// Moves each table slot's record, data block and flag down one slot, then clears the two work buffers.
void func_0015C978(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        *(Head *)((u8 *)&D_00172160->s[0].h + i * 0x420) = *(Head *)((u8 *)&D_00172160->s[1].h + i * 0x420);
        *(Body *)((u8 *)&D_00172160->s[0].b + i * 0x420) = *(Body *)((u8 *)&D_00172160->s[1].b + i * 0x420);
        D_00172160->s[i].f0 = D_00172160->s[i + 1].f0;
    }
    func_0011A518(D_0017327C, 0, 0x1C);
    func_0011A518(D_0017327C + 0x1C, 0, 0x400);
    D_0017327C[-4] = 0;
}
