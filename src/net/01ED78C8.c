/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u8 f10; } A;
typedef struct { char _p0[0x14]; u8 f14; } B;
extern s32 D_00169D58;
void func_01EDEB28(A *, s32, s32, B *);
s32 func_01ED78C8(A *a, s32 a1, B *b) {
    a->f10 = 0;
    b->f14 = 0;
    func_01EDEB28(a, D_00169D58, a1, b);
    if (D_00169D58 >= 999) {
        D_00169D58 = 0;
    } else {
        D_00169D58++;
    }
    return 0;
}
