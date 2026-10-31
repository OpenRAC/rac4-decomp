/* cflags: -O2 -G0 */
#include "common.h"
void func_004FFA10(void);
void func_004FFDD0(int a1, int a2)
{
    switch (a2) {
    case 0:
        *(u8 *)(a1 + 27) = 1;
        break;
    case 1:
        *(int *)(a1 + 8) = 1;
        *(u8 *)(a1 + 27) = 1;
        break;
    case 2:
        *(int *)(a1 + 8) = 2;
        *(u8 *)(a1 + 27) = 1;
        func_004FFA10();
        break;
    }
}
