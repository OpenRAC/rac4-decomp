/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p[200]; } E_c8;
typedef struct { s32 n; char _p4[0x2C]; E_c8 items[1]; } L_c8;
extern void func_001294F0(char *, ...);
extern char D_00193FE0[];
extern char D_001940F0[];
extern char D_00194108[];
extern char D_00194118[];
E_c8 *func_01E9A2B0(L_c8 *list, s32 idx) {
    if (list == 0 || list->n == 0) {
        func_001294F0(D_00193FE0, D_001940F0);
        func_001294F0(D_00194108);
        return 0;
    }
    if (idx <= 0 || list->n < idx) {
        func_001294F0(D_00193FE0, D_001940F0);
        func_001294F0(D_00194118, idx);
        return 0;
    }
    return &list->items[idx - 1];
}
