/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAA020(void *object);
extern s32 func_01EAA098(s32 *arg0);

typedef struct { u8 f0; u8 pad[3]; s32 f4; s32 f8; } Type1;

s32 func_01EA9E28(Type1 *arg0, s32 *arg1) {
    s32 local;
    s32 r;
    if (arg0 == NULL) return 2;
    if (arg0->f0 != 1) return 2;
    r = func_01EAA098(&local);
    if (r != 0) return r;
    if (arg0->f4 != 0 && local == arg0->f8) {
        arg0->f4 = arg0->f4 + 1;
    } else {
        r = func_01EAA020(arg0);
        if (r != 0) return r;
        r = func_01EAA098(&arg0->f8);
        if (r != 0) return r;
        arg0->f4 = arg0->f4 + 1;
    }
    if (arg1 != NULL) *arg1 = arg0->f4;
    return 0;
}
