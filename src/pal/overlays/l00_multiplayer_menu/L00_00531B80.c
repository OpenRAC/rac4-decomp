/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct BufferRecord {
    s32 buffer;
    s32 length;
} BufferRecord;

extern s32 func_004033B0(s32 size);

/* Allocate and record a byte-counted buffer. */
s32 func_L00_00531B80(BufferRecord *record, s32 unused, const u8 *input)
{
    u8 size = *input;
    s32 buffer = func_004033B0(size);

    record->buffer = buffer;
    if (buffer) {
        record->length = size;
        return 0;
    }
    return 16;
}
