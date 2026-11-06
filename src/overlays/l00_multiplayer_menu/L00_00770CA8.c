/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1C];
    s32 f1C;
};

void *func_L00_00770CA8(Type1 *arg0) {
    s32 temp_v1;
    void *var_v0;

    temp_v1 = arg0->f1C;
    var_v0 = NULL;
    if (temp_v1 >= 0) {
        var_v0 = (u8 *)arg0 + ((temp_v1 * 0xC) + 0x30);
    }
    return var_v0;
}
