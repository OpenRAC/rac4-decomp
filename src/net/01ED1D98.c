/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 pad[0x78]; u8 unk78; } Type2;
typedef struct { u8 pad[0x474]; s32 unk474; } Type1;
typedef struct {
    u8 pad[0x38];
    s32 (*unk38)(s32);
    u8 pad3C[0x28];
    s32 (*unk64)(s32, s32);
} Vtbl;

extern Type2 *func_01ED2458(Type1 *arg0);
extern Vtbl *D_00167F3C;

s32 func_01ED1D98(Type1 *arg0) {
    Type2 *v1 = func_01ED2458(arg0);

    if (v1 == 0)
        return 0x17;
    if (v1->unk78 != 0xFF)
        D_00167F3C->unk64(arg0->unk474, v1->unk78);
    D_00167F3C->unk38(arg0->unk474);
    return 0;
}
