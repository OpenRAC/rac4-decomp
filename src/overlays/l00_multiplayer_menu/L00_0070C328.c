/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 id;
    u8 pad[0x28];
} Type1;

extern Type1 D_003B1738[];

s32 func_L00_0070C328(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (arg0 == D_003B1738[i].id) {
            break;
        }
    }
    return i == 5 ? -1 : i;
}
