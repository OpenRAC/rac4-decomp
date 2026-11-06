/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00500D30(s32);                     /* extern */
s32 func_L00_0051CCD0(s32 *);                       /* extern */

s32 func_L00_00507D70(s32 *arg0) {
    if (arg0 != NULL) {
        if ((*arg0 != 0x74) || (func_L00_00500D30(2) != 0)) {
            return func_L00_0051CCD0(arg0);
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
