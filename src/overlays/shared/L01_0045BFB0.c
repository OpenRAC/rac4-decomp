#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef u128 Quadword;
extern s32 func_005BCA78(u16);
extern Quadword func_L01_0045B2F8(const u8 *object);
extern s32 func_L01_005D68E0(u128 *records, u128 vec_a, u128 vec_b);
extern u128 *D_297680[];

/* Look up the record at the linked object's 0x3DC index, then test it against the object with the two helpers. */
s32 func_L01_0045BFB0(u8 *arg0)
{
    u8 *linked = *(u8 **)(arg0 + 0xAC);
    s32 idx = func_005BCA78(*(u16 *)(linked + 0x3DC));
    u128 *rec;
    u128 vec;
    Quadword ret;

    if (idx == -1) return 0;
    rec = D_297680[idx];
    if (rec == 0) return 0;
    vec = *(u128 *)(arg0 + 0x10);
    ret = func_L01_0045B2F8(arg0);
    return (func_L01_005D68E0(rec, vec, ret) ^ 1) & 0xFF;
}
