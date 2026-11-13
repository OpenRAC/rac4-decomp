/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a; s32 b; } Type1;
extern void func_01EA02C8(Type1 *);
extern void func_01EA8C38(void *, Type1);
s32 func_01EA0728(void *arg0) {
    Type1 x;
    if (arg0 == NULL) {
        return 0x17;
    }
    func_01EA02C8(&x);
    func_01EA8C38(arg0, x);
    return 0;
}
