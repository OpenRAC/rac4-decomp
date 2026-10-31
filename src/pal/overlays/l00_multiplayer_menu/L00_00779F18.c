#include "common.h"
extern u8 *D_002234A4;

void func_L00_00779F18(void) {
    void (*cb)(void)=*(void(**)(void))(D_002234A4+0x28); if(cb)cb();
}
