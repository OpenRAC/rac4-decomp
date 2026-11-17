/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 lo; s32 hi; s32 f8; s32 fC; } R_10;
extern void func_001294F0(char *, ...);
extern char D_00194678[];
extern char D_00194680[];
extern char D_00194690[];
R_10 *func_01E9AAC8(s32 key, R_10 *r) {
    for (; r->f8 != 0; r++) {
        if (key >= r->lo && key <= r->hi) {
            return r;
        }
    }
    func_001294F0(D_00194678, D_00194680);
    func_001294F0(D_00194690, key);
    return 0;
}
