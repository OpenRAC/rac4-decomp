/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern char D_1B6898[];
extern s32 func_0011A518(char *p, s32 fill, s32 n);
extern s32 func_01EBDA08(char *buf, char *obj);

/* Publish the object into the 0x108 buffer and hand the id back through OUT. */
s32 func_01EC2310(char *p, s32 *out)
{
    char *buf;
    s32 r;

    if (p == 0) {
        return 2;
    }
    buf = D_1B6898;
    r = func_0011A518(buf, 0, 0x108);
    *(s32 *)(p + 0x24) = 1;
    r = func_01EBDA08(buf, p);
    if (r == 0) {
        *out = *(s32 *)buf;
    }
    return r;
}
