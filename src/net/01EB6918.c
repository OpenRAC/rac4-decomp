/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x84]; s32 f84, f88, f8C, f90; } X;
extern X *D_00167F40;
void func_01EB6978(s32 *);
void func_01EBD798(void);
s32 func_01EB6918(s32 *a) {
    func_01EB6978(a);
    func_01EBD798();
    if (D_00167F40 != 0) {
        D_00167F40->f84 = a[0];
        D_00167F40->f88 = a[1];
        D_00167F40->f8C = a[3];
        D_00167F40->f90 = a[2];
    }
    return 0;
}
