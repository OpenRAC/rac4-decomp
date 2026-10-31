#include "common.h"
extern u8 *D_002234A4;

void func_L00_00779EE8(void) {
    void (*cb)(void)=*(void(**)(void))(D_002234A4+0x24); if(cb)cb();
}
