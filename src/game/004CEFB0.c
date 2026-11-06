/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern int func_004983E8(int);
extern void func_0049B208(int);
extern void func_004CEF18(int);
extern void func_004CF040(void);
extern int func_00505B20(void);
/* Dispatches the current mode to its corresponding handler. */
void func_004CEFB0(void)
{
    int enabled = 0;
    int index = func_00505B20();
    switch (func_004983E8(6)) {
    case 1: break;
    case 2: func_0049B208(index); break;
    case 3: break;
    case 4: break;
    case 5: enabled = 1;
    case 6: func_004CEF18(enabled); break;
    case 7: break;
    case 8: break;
    case 9: break;
    case 10: break;
    case 11: break;
    case 12: break;
    case 13: func_004CF040(); break;
    }
}
