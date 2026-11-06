#include "common.h"

typedef struct {
    u8 pad[0x2B0];
    s32 f2B0;
} Type2;

typedef struct {
    u8 pad[0x2EF4];
    Type2 *f2EF4;
} Type1;

/* Word 0x2B0 of the object at +0x2EF4, or 0 when there is none. */
s32 func_L00_006EA508(Type1 *o) {
    Type2 *p = o->f2EF4;
    if (p != 0) {
        return p->f2B0;
    }
    return 0;
}
