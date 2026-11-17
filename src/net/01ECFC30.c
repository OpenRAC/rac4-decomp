/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x108]; u32 f108; char _p10C[0x10]; u32 f11C; char _p120[0x50]; s32 *f170; s32 *f174; s32 *f178; } Ctx;
extern Ctx *D_00167F38;
s32 func_01ECFC30(s32 *out, s32 a, s32 b, s32 c) {
    if (D_00167F38->f11C >= D_00167F38->f108) {
        return 0x16;
    }
    if (out == 0) {
        return 0x17;
    }
    *out = -1;
    D_00167F38->f170[D_00167F38->f11C] = a;
    D_00167F38->f174[D_00167F38->f11C] = b;
    D_00167F38->f178[D_00167F38->f11C] = c;
    *out = D_00167F38->f11C;
    D_00167F38->f11C++;
    return 0;
}
