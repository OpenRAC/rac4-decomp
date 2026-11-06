#include "common.h"
const char *func_004FDAA0(const char *input, char *output, u32 capacity)
{
    s32 comment = 0;
    s32 quoted = 0;
    u32 i = 0;
    capacity--;
    while (i < capacity) {
        u32 c = *(const u8 *)input;
        if ((u8)c == '"' && ((const u8 *)input)[-1] != '\\')
            quoted = !quoted;
        if ((u8)c == '\n' && !quoted)
            break;
        if (!(u8)c)
            break;
        if ((u8)c == ';')
            comment = !comment;
        if ((u8)c != '\r' && !comment)
            *output++ = c;
        input++;
        i++;
    }
    *output = 0;
    {
        const char *next = input + 1;
        if (!*(const u8 *)input)
            next = input;
        return next;
    }
}
