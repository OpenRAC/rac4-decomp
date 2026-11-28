/* cflags: @ee29 -O2 -G8 */
#include "pal/object_data.h"

extern PalObject *D_L01_00221C98;

s32 func_L01_00492018(void) {
    if (D_L01_00221C98 != NULL) {
        return (s32)D_L01_00221C98->data[0x6C / sizeof(u32)];
    }
    return -1;
}
