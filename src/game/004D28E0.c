#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Entry;

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505328(s32 handle, u32 value);
extern Entry D_003D2A00[];
extern s32 D_003D2A78[5][5];
extern s32 D_002219E0;

// Sets each of the entry's five slot values and its extra value as 0x80969696 on the matching handles.
void func_004D28E0(s32 arg0) {
    s32 i;
    s32 *p;

    func_00505328(func_004A1A60(&D_002219E0, D_003D2A00[arg0].f4), 0x80969696);
    p = D_003D2A78[arg0];
    for (i = 4; i >= 0; i--) {
        func_00505328(func_004A1A60(&D_002219E0, *p++), 0x80969696);
    }
}
