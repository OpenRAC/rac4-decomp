/* cflags: @ee29 -O2 -G8 */
#include "pal/object_data.h"

typedef struct {
    u8 pad00[0x4E];
    u8 flag;
    u8 pad4F[0x15];
    f32 value;
} ObjectFields;

extern PalObject *D_L01_00220C20;
extern u8 D_L01_00390450[];

s32 func_L01_003CD288(void) {
    if (D_L01_00220C20 != NULL) {
        ObjectFields *fields = (ObjectFields *)D_L01_00220C20->data;
        return fields->flag != 0;
    }
    return 0;
}

f32 func_L01_003CD2D8(void) {
    if (D_L01_00220C20 != NULL) {
        ObjectFields *fields = (ObjectFields *)D_L01_00220C20->data;
        return fields->value;
    }
    return 1.0f;
}

s32 func_L01_003CD5D0(s32 index) {
    if (D_L01_00220C20 != NULL) {
        return D_L01_00390450[index] == 0;
    }
    return 0;
}
