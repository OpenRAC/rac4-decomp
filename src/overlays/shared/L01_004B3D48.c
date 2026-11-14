#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern s32 func_005BCA78(u16);
extern u128 func_L01_004B3898(void *);
extern s32 func_L01_005D68E0(u128 *records, u128 vec_a, u128 vec_b);
extern s32 D_297680[];

// Looks up a record by the object's 0x3DC halfword and tests it against the object's 0x10 vector.
s32 func_L01_004B3D48(u8 *a0) {
    s32 *s0;
    s32 *s2;
    u128 vec_a;
    u128 vec_b;

    s2 = D_297680;
    s0 = s2 + func_005BCA78(*(u16 *)(*(u8 **)(a0 + 0xAC) + 0x3DC));
    vec_a = *(u128 *)(a0 + 0x10);
    vec_b = func_L01_004B3898(a0);
    return (func_L01_005D68E0((u128 *)*s0, vec_a, vec_b) ^ 1) & 0xFF;
}
