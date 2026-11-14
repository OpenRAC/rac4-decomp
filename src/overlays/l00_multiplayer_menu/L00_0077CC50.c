#include "common.h"

extern u16 D_00221928[];
extern void func_0015D7A0();
extern void func_1ED5CB8();

// Calls func_1ED5CB8 with a local holding D_00221928[0].
void func_L00_0077CC50(void) {
    u16 buf[16];
    buf[0] = D_00221928[0];
    func_1ED5CB8(buf, func_0015D7A0, 0);
}
