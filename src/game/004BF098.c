#include "common.h"

extern void *func_0054A980(s32 arg0);
extern s32 func_0054AAD8(s32 arg0);

// Switch on arg0 (0..4): case 0 reads a word of func_0054A980(func_0054AAD8(1)), others give constants; -1 otherwise.
s32 func_004BF098(s32 arg0) {
    s32 var_a1 = -1;

    switch (arg0) {
    case 0:
        var_a1 = ((s32 *)func_0054A980(func_0054AAD8(1)))[1];
        break;
    case 1:
        var_a1 = 0x3478;
        break;
    case 2:
        var_a1 = 0x347A;
        break;
    case 3:
        var_a1 = 0x347C;
        break;
    case 4:
        var_a1 = 0x347E;
        break;
    }
    return var_a1;
}
