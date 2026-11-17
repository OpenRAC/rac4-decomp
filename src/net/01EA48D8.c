/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 a; u32 b; } Type1;
extern void func_01EA8B78(Type1 *);
Type1 func_01EA48D8(u8 *arg0) {
    Type1 v;
    func_01EA8B78(&v);
    if (arg0 != NULL) {
        v = *(Type1 *)(arg0 + 0x410);
    }
    return v;
}
