/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef int s128 __attribute__((mode(TI)));
extern s64 func_0047ADF0(s128);

s64 func_L01_0059F500(void *arg0)
{
    return func_0047ADF0(*(s128 *)((u8 *)arg0 + 0x10));
}