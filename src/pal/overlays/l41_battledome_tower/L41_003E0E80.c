#include "common.h"
#include "pal/global_00222894.h"
#include "pal/moby_class.h"
#include "pal/object_data.h"

extern u8 *D_002228B0;

/* Return the linked index for class 0x2075, or find the object in the pool. */
s32 func_L41_003E0E80(void *unused, u8 *object) {
    s32 result;
    u8 *entry;
    s32 index;

    result = -1;
    if (object == 0) {
        return -1;
    }
    if (((PalMobyClassView *)object)->classId == 0x2075) {
        result = (s32)((PalObject *)object)->data[0x2EC / sizeof(s32)];
    } else {
        index = 0;
        for (entry = D_00222894; entry != D_002228B0; entry += 0x100, index++) {
            if (entry == object) {
                result = index;
                break;
            }
        }
    }
    return result;
}
