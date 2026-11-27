/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 source;
    s32 destination;
    u8 pad08[4];
    s32 size;
} CopyRecord;

extern void func_L00_00533820(s32 destination, s32 source, s32 size);

/* Copies the data described by an entry and returns status zero. */
s32 func_L00_00531840(const CopyRecord *record)
{
    func_L00_00533820(record->destination, record->source, record->size);
    return 0;
}
