/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct Type2 {
    char pad0[4];
    s32 f4;
} Type2;

typedef struct Type1 {
    char pad0[0x488];
    Type2 *f488;
} Type1;

Type2 *func_01ED2458(Type1 *arg0) {
    Type2 *t;

    if (arg0 != NULL) {
        t = arg0->f488;
        if (t != NULL && t->f4 != 0) {
            return t;
        }
    }
    return NULL;
}
