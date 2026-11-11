/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004DEE70 (src/levels/39_multiplayer_menu/L39_004DEB90.c, GPL-3.0), the same code in both games. */

typedef struct { int n; int *items; } L;
typedef struct {
    long f0;
    s32 f8;
    s32 pad;
    void (*f10)(s32, s32, L **, s32, long, s32);
} E_004DEE70;
typedef struct { s32 n; E_004DEE70 **items; } T_004DEE70;
extern void func_L00_00508338(L *);
void func_L00_0051AC70(T_004DEE70 *list, s32 arg1, L **arg2) {
    s32 i;
    s32 n;
    E_004DEE70 *e;
    if (list != 0) {
        n = list->n;
        for (i = 0; i < n; i++) {
            e = list->items[i];
            if (e != 0 && e->f10 != 0) {
                e->f10(arg1, func_L00_0051AC38(arg2, i), arg2, i, e->f0, e->f8);
            }
        }
    }
    if (*arg2 != 0) {
        func_L00_00508338(*arg2);
        *arg2 = 0;
    }
}
