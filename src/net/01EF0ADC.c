/* cflags: @ee296 -O2 -G0 -fno-align-jumps */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

void func_01EF0BA8(Type1 *arg0);

Type1 *func_01EF0ADC(Type1 *arg0, s32 arg1) {
    arg0->fC = 0;
    arg0->f4 = 1;
    arg0->f8 = 1;
    arg0->f0 = 1;
    if (arg1 != 0) {
        func_01EF0BA8(arg0);
    }
    
}
