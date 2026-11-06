#include "common.h"
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;
typedef struct {
    u8 prefix[12];
    Cursor cursor;
} Input;
s32 func_0040BAB8(const Input *input, Cursor *output)
{
    u32 remaining;
    u8 *nextData;
    *output = input->cursor;
    remaining = output->remaining;
    if (!remaining || (output->data[0] & 0x80))
        return 0x801;
    goto test;
next:
    {
        u32 nextRemaining = remaining - 1;
        output->data = nextData;
        output->remaining = nextRemaining;
        remaining = nextRemaining;
    }
test:
    if (remaining) {
        u8 *data = output->data;
        nextData = data + 1;
        if (!*data)
            goto next;
    }
    return 0;
}
