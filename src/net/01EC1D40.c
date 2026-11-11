/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair;

typedef struct {
    u8 pad[0x5E];
    u16 flags : 10;
    u16 lo : 6;
} Src;

extern void *func_0011A518(char *p, s32 fill, s32 n);
extern void func_01EA7830(s32 a0, Pair v, s32 a2, u16 *buf, s32 n, s32 *extra);

/* Build the six-word request from the source block and hand it to the writer. */
s32 func_01EC1D40(s32 *a, char *b)
{
    u16 buf[8];
    s32 extra = 0;

    func_0011A518((char *)buf, 0, 6);
    buf[0] = ((Src *)b)->flags | 0x1000;
    func_01EA7830(a[0], *(Pair *)(b + 8), *(s32 *)(b + 0x10), buf, 6, &extra);
    return 0;
}
