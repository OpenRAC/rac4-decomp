/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"
#include "pal/menu_session.h"

typedef struct Type1 Type1;

struct Type1 {
    u8 pad[0x2C];
    u32 f2C;
    u8 pad30[0x80];
    PalMenuSession *fB0;
    u8 padB4[0x28];
    void *fDC;
};

extern s32 func_L00_005011E0(Type1 *);
extern s32 func_L00_00507D18(void *, void *);

// Marks the active session invalid and removes it when the connection state permits.
s32 func_L00_005080C0(Type1 *arg0)
{
    s32 mode;

    if (arg0->fB0 != NULL && !(arg0->f2C & 1)) {
        mode = func_L00_005011E0(arg0) & 0x3000;
        if (mode != func_L00_005011E0(arg0) &&
            !(func_L00_005011E0(arg0) & 0x4000) &&
            func_L00_005011E0(arg0) != 3) {
            arg0->fB0->f8C = 1;
            func_L00_00507D18(arg0->fDC, arg0->fB0);
            return 1;
        }
    }
    return 0;
}
