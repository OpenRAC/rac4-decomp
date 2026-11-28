#include "common.h"

typedef struct {
    u8 pad00[0xBC];
    s16 classId;
    u8 padBE[0x42];
} StationMoby;

extern u8 *D_00222E14;
extern u8 *D_00222E2C;
extern void func_L01_00517700(u8 *moby, s32 arg0);

void func_L01_00517950(s32 arg0) {
    u8 *moby;

    moby = D_00222E14;
    if (moby < D_00222E2C) {
        do {
            if (((StationMoby *)moby)->classId == 0x26CA) {
                func_L01_00517700(moby, arg0);
            }
            moby += sizeof(StationMoby);
        } while (moby < D_00222E2C);
    }
}
