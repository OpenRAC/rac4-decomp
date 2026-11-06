/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern int func_00499120(int);
extern void func_0049BF40(int);
extern void func_004CFDB8(int);
extern void func_004CFEE0(void);
extern int func_00506BB8(void);
/* Dispatches the current mode to its corresponding handler. */
void func_004CFE50(void)
{
    int enabled = 0;
    int index = func_00506BB8();
    switch (func_00499120(6)) {
    case 1: break;
    case 2: func_0049BF40(index); break;
    case 3: break;
    case 4: break;
    case 5: enabled = 1;
    case 6: func_004CFDB8(enabled); break;
    case 7: break;
    case 8: break;
    case 9: break;
    case 10: break;
    case 11: break;
    case 12: break;
    case 13: func_004CFEE0(); break;
    }
}
