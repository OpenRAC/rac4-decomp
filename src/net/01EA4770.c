/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p[0x46C]; s32 f46C; } Obj;
extern s32 D_001AF918[];
void func_01EA48A8(Obj *, s32);
void func_01EA06A8(s32 *);
void func_01EA4770(Obj *o) {
    s32 i;
    if (o == 0) {
        return;
    }
    for (i = 0; i < 256; i++) {
        func_01EA48A8(o, i);
    }
    func_01EA06A8(&D_001AF918[o->f46C]);
}
