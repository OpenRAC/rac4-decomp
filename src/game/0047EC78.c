#include "common.h"

extern void *func_00510BE8();
typedef struct {
    u8 pad[0x5F0];
    u8 f5F0[10];
} Type1;
extern Type1 D_354630[];

// Returns byte f5F0[idx] of D_354630 for idx = the word at 0x2F14 of func_00510BE8's object, or 0 when null or idx >= 10.
u8 func_0047EC78(void) {
    u8 var_s0;
    void *temp_v0;
    u32 temp_v1;

    var_s0 = 0;
    temp_v0 = func_00510BE8();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v1 = *(u32 *)((u8 *)temp_v0 + 0x2F14);
    if (temp_v1 < 0xA) {
        var_s0 = D_354630[0].f5F0[temp_v1];
    }
    return var_s0;
}
