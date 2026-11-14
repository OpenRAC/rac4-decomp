/* cflags: -G0 */
#include "common.h"

typedef struct { u16 id; char _p2[6]; } E;
extern E *D_0023F440;
s32 func_0045EB08(s32 id) {
    s32 i;
    for (i = 0; D_0023F440[i].id != 0xFFFF && D_0023F440[i].id != id; i++) {
    }
    if (i >= 0x400) {
        return -1;
    }
    return i;
}
