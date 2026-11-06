#include "common.h"

typedef struct {
    s16 id;
    u8 pad2[0x12];
    s32 unk14;
    s32 timer;
} Slot;

typedef struct {
    u8 pad0[0x14C];
    s32 flags;
    u8 pad150[0x20];
} Player;

typedef struct {
    u8 pad0[8];
    f32 time;
    s32 timer;
} State;

extern s32 D_0021DE3C;
extern s32 *D_0021DE2C;
extern Slot D_00308560[64];
extern State D_00308C60;
extern Player D_00308C80[];

extern s32 func_00453D20(s32 *);
extern s32 func_00453CE8(s32 *);

// Once per frame (when D_0021DE3C is 0): frees every one of the 64 slots of D_00308560 whose
// timer runs out (id -1), and when the timer of D_00308C60 runs out sets it back to 30 and sets
// bit 0x20 in the flags of each player of D_00308C80. Then adds 1/50 s to the clock at +8.
void func_004AAA48(void) {
    s32 i;

    if (D_0021DE3C == 0) {
        for (i = 0; i < 64; i++) {
            if (D_00308560[i].id != -1 && func_00453D20(&D_00308560[i].timer) != 0) {
                D_00308560[i].id = -1;
                D_00308560[i].unk14 = 0;
            }
        }
        if (func_00453CE8(&D_00308C60.timer) != 0) {
            D_00308C60.timer = 30;
            for (i = 0; i < *D_0021DE2C; i++) {
                D_00308C80[i].flags |= 0x20;
            }
        }
    }
    D_00308C60.time += 0.020000001f;
}
