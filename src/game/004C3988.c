#include "common.h"

typedef struct Type1 { s32 f0; s32 f4; } Type1;
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_004C3820(s32);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern Type1 D_003D2298[];
extern s32 D_221888;
extern u8 D_30B7F8[];

/* Passes the owner's D_003D2298 entry (via func_004A1A60) and func_004C3820's value to func_00505328. */
void func_004C3988(void) {
    s32 owner = func_00505B20();
    u8 *root = owner * 0x74 + D_30B7F8;
    func_00505328(func_004A1A60(&D_221888, D_003D2298[*(s32 *)(root + 0x14)].f0), func_004C3820(*(s32 *)(root + 0x14)));
}
