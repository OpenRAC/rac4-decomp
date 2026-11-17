/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x20]; s32 f24[3]; s32 f30; } Ent_34;
extern Ent_34 *D_001B23C8;
extern s32 func_01EAB2A0(s32 *, u32 *);
extern s32 func_01EA95C0(s32 *);
s32 func_01EAADE8(void) {
    u32 i;
    u32 t;
    if (D_001B23C8 == 0) {
        return 0;
    }
    for (i = 0; i < 256; i++) {
        if (D_001B23C8[i].f0 != 0) {
            func_01EAB2A0(D_001B23C8[i].f24, &t);
            if (t > 30000) {
                func_01EA95C0(&D_001B23C8[i].f30);
                D_001B23C8[i].f0 = 0;
            }
        }
    }
    return 0;
}
