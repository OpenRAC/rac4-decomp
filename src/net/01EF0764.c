/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x2020];
    s32 f2020;
};

void func_0011A518(void *, s32, s32);

void func_01EF0764(Type1 *arg0) {
    func_0011A518(arg0, 0, 0x2020);
    arg0->f2020 = 0;
}
