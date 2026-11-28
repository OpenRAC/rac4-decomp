/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;

typedef struct {
    u8 prefix[12];
    Cursor cursor;
} Input;

typedef struct {
    u8 *buf;
    s32 len;
} Req;

extern s32 func_0040BAB8(const Input *, Cursor *);
extern void func_00403308(void *, s32, u32);
extern void func_00403330(void *, const void *, u32);

s32 func_0040BA40(const Input *input, Req *request)
{
    Cursor cursor;
    s32 result = func_0040BAB8(input, &cursor);
    u32 remaining;
    u32 length;
    u32 padding;

    if (result != 0)
        return result;
    remaining = cursor.remaining;
    result = 0x801;
    length = (u32)request->len;
    if (length < remaining)
        return result;
    padding = length - remaining;
    func_00403308(request->buf, 0, padding);
    func_00403330(request->buf + padding, cursor.data, cursor.remaining);
    return 0;
}
