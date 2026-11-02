/* Call the helper with the 32-bit field at +4, then store its return word through the first argument. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};

s32 func_L00_005664A8(s32);

void func_L00_00566D00(s32 *arg0, Type1 *arg1) {
    *arg0 = func_L00_005664A8(arg1->f4);
}
