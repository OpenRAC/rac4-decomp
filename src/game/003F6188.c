/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern u64 D_003CA120;
s32 func_003F6188(void) {
    D_003CA120 = D_003CA120 * 0x5851F42D4C957F2DULL + 1;
    return (D_003CA120 >> 32) & 0x7FFFFFFF;
}
