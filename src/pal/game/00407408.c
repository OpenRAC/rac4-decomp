/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x14];
    s32 (*f14)();
};
struct Type1 {
    char _p0[0xC];
    Type2 *f10;
    char _p14[0xC];
    s32 f20;
};

s32 func_00408260(s32);

s32 func_00407408(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->f10->f14(arg0->f20);
    if (temp_v0 != 0) {
        return func_00408260(temp_v0);
    }
    return 0;
}
