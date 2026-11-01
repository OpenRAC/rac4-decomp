#include "common.h"
extern u8 *D_002233A4;

void func_L00_00774B10(void) {
    void (*cb)(void)=*(void(**)(void))(D_002233A4+0x24); if(cb)cb();
}
