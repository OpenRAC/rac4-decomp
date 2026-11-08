/* cflags: @ee296 -O1 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 { u8 f0[0x1041c]; Type2 *f1041c; };
struct Type2 {
    u8 f0[0xc];
    void *(*fc)(Type1 *, u32, u32, s32, const char *);
    void (*f10)(Type1 *, void *);
};
/* Forward an allocation request through the object table. */
void *func_001565A0(Type1 *p, u32 size, u32 align, s32 line, const char *file)
{
    return p->f1041c->fc(p, size, align, line, file);
}
