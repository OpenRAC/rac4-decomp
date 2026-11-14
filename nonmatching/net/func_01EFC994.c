/* Not matching yet: BYTES 79/128 (@ee32-030926, first at retail size; was SIZE 124/128). Not part of the build. */
/* cflags: @ee32-030926 -O2 -G0 */
#include "common.h"

typedef struct {
    char f0[0x7C];
    f32 (*f7C)(void *, s32, s32);
} Type2;

typedef struct {
    char f0[0xB0];
    Type2 *fB0;
    char fB4[0x20C];
    s32 f2C0;
    char f2C4[0x18];
    s32 f2DC;
    s32 f2E0;
    char f2E4[0x200];
    f32 f4E4;
} Type1;

extern s32 func_01EFCE48(char *, s32);

void func_01EFC994(Type1 *arg0) {
    f32 (*fn)(void *, s32, s32);
    char *temp;

    fn = arg0->fB0->f7C;
    for (;;) {
        temp = (char *)arg0 + 0xB8;
        if (!(arg0->f4E4 < fn(arg0, arg0->f2DC, arg0->f2C0))) {
            break;
        }
        arg0->f2DC = func_01EFCE48(temp, arg0->f2DC);
        arg0->f2E0 = func_01EFCE48(temp, arg0->f2E0);
        fn = arg0->fB0->f7C;
    }
}
