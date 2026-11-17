/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } Type1;
extern s32 func_00126BA0(Type1 *);
s32 func_01EA9F90(u8 *arg0) {
    Type1 q;
    s32 r;
    if (arg0 == NULL) {
        return 2;
    }
    *(s32 *)(arg0 + 0x10) = 0;
    q.f4 = 1;
    q.f8 = 1;
    r = func_00126BA0(&q);
    if (r == -1) {
        return 0x384;
    }
    *(s32 *)(arg0 + 0xC) = r;
    return 0;
}
