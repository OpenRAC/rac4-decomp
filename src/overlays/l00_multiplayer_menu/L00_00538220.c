/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0x104];
    s32 f108;
};

void func_0011A518(void *, s32, s32);

void func_L00_00538220(Type1 *arg0) {
    func_0011A518(arg0, 0, 0x110);
    arg0->f0 = 0;
    arg0->f108 = 0;
}
