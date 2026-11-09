/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 D_0016A078[];

u32 func_01EDB438(u32 arg0) {
    if (arg0 >= 0xFFFFFFFF) {
        if (D_0016A078[0] == 0xFFFFFFFF) {
            D_0016A078[0] = 0;
        }
        D_0016A078[0] = D_0016A078[0] + 1;
        return D_0016A078[0];
    }
    return arg0;
}
