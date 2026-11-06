/* cflags: @ee29 */
#include "common.h"
void *func_L00_004FACD8(s32);                   /* extern */
s32 func_L00_00538220(void *);                  /* extern */

void *func_L00_005381D8(void) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = func_L00_004FACD8(0x110);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        func_L00_00538220(temp_v0);
        (*(s32 *)((u8 *)(temp_v0) + 0x108)) = 1;
        var_v0 = temp_v0;
    }
    return var_v0;
}
