/* Not matching yet: SIZE ours 164 / retail 172 (tools/try_func.py func_01EBB030 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EB8E98(s32, s32);
extern s32 func_01EBAE58(s32, s32, s32, void *);

typedef struct {
    void *p;
    s32 n;
    u8 pad[0x38];
    s32 f40;
    s32 f44;
} Desc;

s32 func_01EBB030(u8 *arg0, s32 arg1)
{
    s32 res = 0xD4E6;
    u32 idx = arg1 & 0xFFFF;

    if (idx < *(u16 *)(arg0 + 0x19C)) {
        u8 buf[0x10];
        Desc *d = (Desc *)(buf + 0x10);

        *(u16 *)(buf + 0x00) = func_01EB8E98(2, 4);
        d->f40 = 0;
        d->f44 = 0;
        *(u8 *)(buf + 0x02) = *(u8 *)(arg0 + 0x1B8);
        d->p = buf;
        d->n = 4;
        d->f40 = 4;
        d->f44 = 1;
        res = func_01EBAE58((s32)arg0,
                            *(s32 *)(arg0 + 0x184) + ((idx * 5) << 4),
                            0xF000, d);
    }
    return res;
}
