#include "common.h"
typedef struct {
    u8 prefix[0x1C];
    s32 first, second;
    u8 suffix[0x10];
} Record;
typedef struct {
    u8 prefix[0xC];
    s32 first, second;
    u8 suffix[8];
} State;
extern State D_003096B0;
extern Record D_003096D0[2];
extern void func_00453E20(void *, s32, u32);
void func_004B0D40(void)
{
    s32 *record;
    s32 i;
    func_00453E20(&D_003096B0, 0, sizeof(D_003096B0));
    func_00453E20(D_003096D0, 0, sizeof(D_003096D0));
    record = &D_003096D0[0].second;
    for (i = 1; i >= 0; i--, record = (s32 *)((u8 *)record + 0x34)) {
        record[-1] = -1;
        record[0] = -1;
    }
    D_003096B0.first = -1;
    D_003096B0.second = -1;
}
