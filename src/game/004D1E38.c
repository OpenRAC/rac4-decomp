/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 func_00505B20(void);
extern s32 func_004983E8(s32);
extern void func_0049B208(s32);
extern void func_004D1DA0(s32);
extern void func_004D1EC8(void);
/* Dispatches the selected action using the resolved argument. */
void func_004D1E38(void)
{
    s32 mode = 0;
    s32 value = func_00505B20();
    switch (func_004983E8(6)) {
    case 1: break;
    case 2: func_0049B208(value); break;
    case 3: break;
    case 4: break;
    case 5: mode = 1;
    case 6: func_004D1DA0(mode); break;
    case 7: break;
    case 8: break;
    case 9: break;
    case 10: break;
    case 11: break;
    case 12: break;
    case 13: func_004D1EC8(); break;
    }
}
