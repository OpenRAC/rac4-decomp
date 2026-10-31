#include "common.h"

/* Looks up the record for the current owner in D_30B7F8, takes a value from D_003D2180 and D_221880, and passes the results to func_00505328. */
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern u32 func_004C2EE0(s32 a0, s32 a1);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
typedef struct { s32 f0; s32 f4; s32 f8; } Type2;
typedef struct { u8 pad[0xC]; s32 fC; u8 pad2[0x74 - 0x10]; } Type1;
extern Type2 D_003D2180[];
extern s32 D_221880[];
extern Type1 D_30B7F8[];

void func_004C2F78(void) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = D_30B7F8[func_00505B20()].fC;
    temp_s0 = func_004A1A60(D_221880, D_003D2180[temp_s1].f0);
    func_00505328(temp_s0, func_004C2EE0(temp_s1, 0));
}
