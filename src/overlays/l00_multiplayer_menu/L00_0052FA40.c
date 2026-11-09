/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
};

s32 func_004FAD28(void *);
s32 func_005362F8(s32);
s32 func_00542440(s32);
s32 func_L00_0051D000(s32);

void func_L00_0052FA40(Type1 *arg0) {
    s32 temp_a0;

    if (arg0 != NULL) {
        func_00542440(arg0->f0);
        func_005362F8(arg0->f4);
        temp_a0 = arg0->f8;
        if (temp_a0 != 0) {
            func_L00_0051D000(temp_a0);
        }
        func_004FAD28(arg0);
    }
}
