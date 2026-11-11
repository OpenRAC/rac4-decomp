/* cflags: @ee296 -O2 -G8 -falign-loops=1 -fno-schedule-insns */
#include "common.h"
typedef void (*Fn)(void *o, s32 a);
void func_01F04C74(char *obj, s32 arg)
{
    s32 i = 0;
    void **p;
    void *o;
    void *f;
    if (*(s32 *)(obj + 0x28) > 0) {
        p = (void **)obj;
        do {
            o = *p++;
            f = ((void **)o)[0x18D];
            f = ((void **)f)[3];
            ((Fn)f)(o, arg);
            i++;
        } while (i < *(s32 *)(obj + 0x28));
    }
}
