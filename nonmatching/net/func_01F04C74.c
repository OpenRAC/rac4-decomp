/* Not matching yet: BYTES 2/120 (tools/try_func.py func_01F04C74 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 -falign-loops=1 */
#include "common.h"
typedef void (*Fn)(void *o, s32 a);
void func_01F04C74(char *obj, s32 arg)
{
    s32 i = 0;
    void **p;
    void *o;
    if (*(s32 *)(obj + 0x28) > 0) {
        p = (void **)obj;
        do {
            o = *p++;
            (*(Fn *)(*(char **)((char *)o + 0x634) + 0xC))(o, arg);
            i++;
        } while (i < *(s32 *)(obj + 0x28));
    }
}
