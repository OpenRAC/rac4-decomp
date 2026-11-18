/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_0019D048[];
extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_01EE394C(s32 *arg0);
extern s32 func_01EE3A18(s32, void *);
extern void **func_01EFF990(void);

/* Finds an entry whose name matches, once a handler accepts the key. */
void *func_01EF7CD0(s32 a0, s32 *a1, void **a2)
{
    void **p;
    void *e;
    s32 i;
    s32 s;

    p = func_01EFF990();
    while (!(*(s32 (**)(void *, s32 *))((u8 *)*p + 0x18))(p, a1)) {
        a1 = (s32 *)func_01EE394C(a1);
        if (!a1) return 0;
    }
    s = func_01EE3A18((s32)a1, D_0019D048);
    for (i = 0; i < 0x100; i++) {
        e = a2[i];
        if (e) {
            e = (void *)(*(s32 (**)(void *))(*(u8 **)((u8 *)e + 0xB0) + 0x3C))(e);
            if (!func_0011A8A0((const char *)e, (const char *)s)) return a2[i];
        }
    }
    return 0;
}
