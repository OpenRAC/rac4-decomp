#include "common.h"
#include "pal/profile_001721E0.h"

typedef struct Moby {
    u8 pad[0x100];
} Moby;

extern Moby *D_00222E14;
extern s32 D_0021E8A4;
extern s32 *func_L01_0066B300(Moby *);
extern s32 *func_L01_006B3F70(Moby *);
extern s32 func_L01_006BAA18(s32, s32, s32, s32, s32, s32, s32, s32, s32);

// moby index
s32 func_L01_006BA920(s32 *obj, s32 arg1, u8 arg2, Moby *moby, s32 arg4, s32 arg5) {
    u32 id;
    s32 *p;

    if (D_001721E0.f10 < 0) {
        return -1;
    }
    id = 0;
    if (D_0021E8A4 != 1) {
        if (moby != NULL) {
            id = moby - D_00222E14;
        } else {
            id = -1;
        }
    } else {
        p = func_L01_0066B300(moby);
        if (p != NULL) {
            id = *p;
        } else {
            p = func_L01_006B3F70(moby);
            if (p != NULL) {
                id = *p;
            }
        }
    }
    return func_L01_006BAA18(*obj, id, arg1, 1, arg2, 0, 0, arg4, arg5);
}
