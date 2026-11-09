/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0x4];
    s32 f8;
    s32 fC;
};

s32 func_01EF0A58(s32);

void func_01EF0C54(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = func_01EF0A58(arg0->fC);
    arg0->f8 = temp_v0;
    arg0->f0 = temp_v0;
}
