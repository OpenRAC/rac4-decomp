#include "common.h"
extern u8 *D_002233A4;

void func_L00_00774B40(void) {
    void (*cb)(void)=*(void(**)(void))(D_002233A4+0x28); if(cb)cb();
}
