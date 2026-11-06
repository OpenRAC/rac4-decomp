/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Record Record;
typedef struct Container Container;
extern s32 func_L00_00520DE8(Container *container, u32 category, u32 key,
                             s32 *cursor, Record **output, u32 flags);

s32 func_L00_00520EE0(Container *container, u32 category, const u32 *keys)
{
    s32 cursor = 0;
    Record *record;
    s32 status;

    while (*keys != 0) {
        status = func_L00_00520DE8(container, category, *keys,
                                   &cursor, &record, 4);
        if (status != 0)
            return status;
        ++keys;
    }
    return 0;
}
