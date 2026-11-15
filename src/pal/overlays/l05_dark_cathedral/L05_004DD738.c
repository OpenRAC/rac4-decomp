/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef unsigned int Quadword __attribute__((mode(TI)));
s32 func_0047C378(Quadword, s32);                       /* extern */
u8 *func_0047DE20(void);                                /* extern */
#include "pal/l05_00363038.h"

s32 func_L05_004DD738(void *arg0) {
    s32 var_16_2;
    s32 var_17;
    s32 var_18;
    u8 **var_16;
    void *temp_2;
    void *temp_5;
    void *var_3;

    temp_5 = *(void **)((u8 *)arg0 + 0xAC);
    if (*(u8 *)((u8 *)temp_5 + 0x54A) == 0) {
        goto block_2;
    }
    var_18 = *(s32 *)((u8 *)temp_5 + 0x534);
    goto block_4;
block_2:
    var_18 = *(s32 *)((u8 *)temp_5 + 0x540);
block_4:
    if (var_18 != -1) {
        goto block_7;
    }
    return 1;
block_6:
    return 0;
block_7:
    var_17 = 0;
    var_16 = D_00363038;
    var_3 = *var_16;
    do {
        if (var_3 != 0 && func_0047C378(*(Quadword *)((u8 *)var_3 + 0xA0), var_18) == 0) return 0;
        var_3 = *++var_16;
    } while (++var_17 < 10);
    var_16_2 = 0;
loop_14:
    temp_2 = *(void **)((u32)func_0047DE20() + ((u32)var_16_2 << 2) + 0x1D0);
    if (temp_2 == NULL) {
        goto block_18;
    }
    if (func_0047C378(*(Quadword *)((u8 *)temp_2 + 0x10), var_18) == 0) {
        goto block_17;
    }
    goto block_18;
block_17:
    goto block_6;
block_18:
    var_16_2 = var_16_2 + 1;
    if (var_16_2 < 4) {
        goto loop_14;
    }
    return 1;
}
