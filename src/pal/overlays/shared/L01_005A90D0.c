/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

typedef struct {
    s32 fields[4];
    s32 value;
    s32 reserved;
} Entry;
extern Entry D_003B7F30[];

s32 func_L01_005A90D0(s32 key)
{
    s32 i = 0;
    do {
        if (D_003B7F30[i].fields[1] == key) {
            return D_003B7F30[i].value;
        }
        i++;
    } while (i < 8);
    return 0;
}
