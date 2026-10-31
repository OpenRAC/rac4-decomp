/* cflags: -mno-split-addresses */
#include "common.h"
typedef int quad __attribute__((mode(TI)));
extern char D_00222110[];
extern long func_004FF558(void *, quad, quad, long, float, float, long);
long func_004788A8(quad a, quad b, long c, float d) {
    return func_004FF558(D_00222110, a, b, c, d, 0.0f, 0);
}
