#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0xB4];
    s32 fB4;
};
struct Type2 {
    char _p0[0x268];
    s32 f268;
    char _p26C[0xD];
    s8 f279;
};

s8 func_00741758(s32);
extern Type1 *D_00220D14;

s32 func_L00_0071AC10(Type2 *arg0) {
    s32 temp_v0_2;
    s8 temp_v0;

    temp_v0_2 = D_00220D14->fB4;
    arg0->f268 = temp_v0_2;
    temp_v0 = func_00741758(temp_v0_2);
    arg0->f279 = temp_v0;
    return temp_v0 & 0xFF;
}
