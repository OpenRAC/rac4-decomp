#include "common.h"
extern s32 D_00172160[];

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x13A0];
    s32 f13A0;
};

s32 func_01E9A7C8();
s32 func_L00_00733C70();

s32 func_L00_00733B68(Type1 *arg0) {
    arg0->f13A0 = func_L00_00733C70();
    func_01E9A7C8();
    D_00172160[0] = 2;
    return 0;
}
