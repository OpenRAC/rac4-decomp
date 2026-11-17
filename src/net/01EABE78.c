/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B25B8[];
extern u32 D_00168BB0;
extern void func_01EABA70(void *, u32 *);
extern void func_01EAB270(void *);
void func_01EABE78(s32 *arg0) {
    u32 x;
    *arg0 = 0;
    func_01EABA70(D_001B25B8, &x);
    if (x >= D_00168BB0) {
        *arg0 = 1;
        func_01EAB270(D_001B25B8);
    }
}
