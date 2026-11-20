/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char pad4[8]; s32 fC; } Type1;
typedef struct { s32 f0; s32 f4; } Type2;
extern void func_L00_00533820(s32, s32, s32);

s32 func_L00_00531930(Type1 *arg0, Type2 *arg1) {
    if (arg0->fC != arg1->f4) {
        return 6;
    }
    func_L00_00533820(arg0->f0, arg1->f0, arg0->fC);
    return 0;
}
