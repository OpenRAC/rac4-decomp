/* cflags: -O2 -G8 */
#include "common.h"
extern void *func_0054A290(int, int);
void func_004EEEE0(int a1, int a2, int a3)
{
    void *p = func_0054A290(a2, 0);
switch (a2) {
    case 2: if (a3 == 9) *(short *)(a1 + 116) = 1; else *(short *)(a1 + 116) = 0; break;
    case 3: if (a3 == 9) *(short *)(a1 + 116) = 49; else *(short *)(a1 + 116) = 3; break;
    case 6: if (a3 == 9) *(short *)(a1 + 116) = 15; else *(short *)(a1 + 116) = 0; break;
    case 7: if (a3 == 9) *(short *)(a1 + 116) = 7; else *(short *)(a1 + 116) = 0; break;
    case 4: if (a3 == 9) *(short *)(a1 + 116) = 12; else *(short *)(a1 + 116) = 3; break;
    case 8: if (a3 == 9) *(short *)(a1 + 116) = 15; else *(short *)(a1 + 116) = 1; break;
    case 5: if (a3 == 9) *(short *)(a1 + 116) = 6; else *(short *)(a1 + 116) = 1; break;
    case 15: if (a3 == 9) *(short *)(a1 + 116) = 31; else *(short *)(a1 + 116) = 3; break;
    case 9:
        if (*(short *)(a1 + 188) == 9458) {
            if (a3 == 9) *(short *)(a1 + 116) = 3; else *(short *)(a1 + 116) = 0;
        } else if (*(short *)(a1 + 188) == *(short *)((char *)p + 60)) {
            if (a3 == 9) *(short *)(a1 + 116) = 7; else *(short *)(a1 + 116) = 6;
        }
        break;
    }
}
