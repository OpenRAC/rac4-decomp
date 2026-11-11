/* Not matching yet: SIZE 60/36 (tail-call form; tools/try_func.py func_001559E0 build/try/func_001559E0/p1.c --diff) (tools/try_func.py func_001559E0 --diff). Not part of the build. */
#include "common.h"

typedef struct Type1 {
    u8 f0[3];
    u8 f3;
} Type1;

void func_00155908(Type1 *);

void func_001559E0(Type1 *arg0) {
    if (arg0->f3 == 0) {
        arg0->f3 = 0x17;
        func_00155908(arg0);
    } else {
        arg0->f3--;
    }
}
