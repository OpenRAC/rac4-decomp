#include "pal/record_001F1480.h"

void func_0045E708(void) {
    s32 i;
    for (i = 0; i < 2088; i++) {
        D_001F1480[i].f8 &= 0x7FFFFFFF;
    }
}
