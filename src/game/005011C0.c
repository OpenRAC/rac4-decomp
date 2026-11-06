#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 *f4;
};


s32 func_005011C0(Type1 *arg0, u32 arg1, s32 arg2) {
    s32 *temp_v0;

    if (arg1 < 8U) {
        temp_v0 = arg0->f4 + arg1;
        if (*temp_v0 == 0) {
            *temp_v0 = arg2;
            return 1;
        }
    }
    return 0;
}
