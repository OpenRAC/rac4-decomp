/* cflags: -O2 -G8 */
#include "common.h"
extern int D_0021DE40;
extern short D_0024798C[];
extern int func_L15_004D8480(int *, int, int, int, int, int, int, int);
extern void func_0045DFC8(int, int, int, int, float, float, float, float);
void func_L15_004D8680(int a1)
{
    int *p = *(int **)(a1 + 172);
    if (D_0021DE40 - 3000 >= p[138] && D_0021DE40 - 750 >= p[135] && !D_0024798C[0]) {
        p[134] = func_L15_004D8480(p + 139, 6, 11008, 11013, 11051, 11053, 11070, 11074);
        if (p[134] >= 0) {
            p[138] = D_0021DE40;
            p[135] = D_0021DE40;
            func_0045DFC8(*(short *)(p + 134), -1, 2, 0, 0.75f, 1.0f, 0.0f, 64.0f);
        }
    }
}
