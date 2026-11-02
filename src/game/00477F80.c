/* cflags: -mno-split-addresses */
#include "common.h"
typedef int quad __attribute__((mode(TI)));
extern char D_00222010[];
extern long func_004FE4E8(void *, quad, quad, long, float, float, long);
long func_00477F80(quad a, quad b, long c, float d) {
    return func_004FE4E8(D_00222010, a, b, c, d, 0.0f, 0);
}
