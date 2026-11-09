/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x18];
    s32 f18;
};
struct Type1 {
    char _p0[0x18];
    s32 f18;
    char _p1C[0x8];
    Type2 *f24;
};

void func_L00_004F71F0(void *, s32);
s32 func_L00_004F7240(void *);

void func_L00_00516E90(Type1 *arg0) {
    func_L00_004F71F0(arg0, func_L00_004F7240(arg0->f24));
    arg0->f18 = (s32) arg0->f24->f18;
}
