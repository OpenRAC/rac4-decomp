/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EA95C0(void **);
s32 func_01EC26C8(void *arg0) {
    void *p = NULL;
    if (arg0 == NULL) {
        return 2;
    }
    p = arg0;
    func_01EA95C0(&p);
    return 0;
}
