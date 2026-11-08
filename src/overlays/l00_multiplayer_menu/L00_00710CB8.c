/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x58];
    void *f58;
};

s32 func_L00_00710750();
s32 func_L00_00710D30(void *, s32);
extern s32 D_004B7C58[];

void *func_L00_00710CB8(Type1 *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    arg0->f58 = D_004B7C58;
    func_L00_00710D30(arg0, arg1);
    return arg0;
}
