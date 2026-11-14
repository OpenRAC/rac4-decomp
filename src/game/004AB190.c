#include "common.h"

extern s32 func_00505B20(void);

typedef struct {
    s16 f0;
    u8 pad2[0x12];
    s32 f14;
    u8 pad18[4];
} Rec28;

typedef struct {
    u8 pad0[0x158];
    s32 f158;
    s32 f15C;
    s32 (*f160)(s32, s32, s32);
    s32 f164;
    s32 f168;
    u8 pad16C[4];
} Rec368;

extern Rec28 D_308460[];
extern Rec368 D_308B80[];

// Checks a halfword record against the second table and, when the record has a hook, calls it.
s32 func_004AB190(s32 arg0) {
    s32 (*temp_a3)(s32, s32, s32);
    s32 temp_t3;

    temp_t3 = func_00505B20();
    if ((arg0 < 0) || (D_308460[arg0].f0 != D_308B80[temp_t3].f158)) {
        return 0;
    }
    temp_a3 = D_308B80[temp_t3].f160;
    return (temp_a3 != 0) ? temp_a3(temp_t3, D_308460[arg0].f14, D_308B80[temp_t3].f168) : 1;
}
