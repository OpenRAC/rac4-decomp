#include "common.h"

extern void func_004E7450(s32 *);
extern s32 D_001170D0[];
extern s32 D_266A88[];

// Get value from array using scaled argument
s32 func_0046D820(s32 arg0) {
    func_004E7450(D_001170D0);
    return D_266A88[arg0];
}
