/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004DED48 (src/levels/39_multiplayer_menu/L39_004DEB90.c, GPL-3.0), the same code in both games. */

typedef struct { int n; int *items; } L;
extern L *func_L00_00508028(int);
extern void func_L00_004F84C8(int, int, int, int, int);
extern int func_L00_005081E0(L *, int);
int func_L00_0051AB48(L **a, int idx, int val) {
    int i;
    if (*a == 0) {
        *a = func_L00_00508028(0);
        if (*a == 0) {
            func_L00_004F84C8(0x26, 0x65, 0x21, 0, 0);
            return 0;
        }
    }
    if (idx < 0) idx = 0;
    for (i = (*a)->n; i <= idx; i++) {
        if (!func_L00_005081E0(*a, 0)) {
            func_L00_004F84C8(0x26, 0x65, 0x21, 0, 0);
            return 0;
        }
    }
    (*a)->items[idx] = val;
    return 1;
}
