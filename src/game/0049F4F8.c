#include "common.h"

extern s32 D_00307254[];
extern s32 func_00505B20(void);
extern s32 func_004A0208(s32);
extern s32 func_0049F9F0(s32);
extern void func_0049FB78(s32);
extern void func_0049F928(s32);
extern f32 func_004973E0(void *, s32);
extern void func_0049FBF0(s32);
extern void func_00499CE0(s32);
extern void func_005054F8(s32, s32);

void func_0049F4F8(void) {
    s32 index = func_00505B20();
    s32 *record = D_00307254 + index * 0x80;
    f32 value;
    f32 zero;
    s32 first;
    s32 second;

    if (((u8 *)record)[0x24] != 0) {
        if (*(f32 *)(record + 0xA) == 1.0f && record[0xC] == record[0xD]) {
            if (func_0049F9F0(func_004A0208(index)) == 0) {
                func_0049FB78(1);
            }
            func_0049F928(index);
            return;
        }
    }
    value = *(f32 *)(record + 0xA);

fallback:
    zero = 0.0f;
    if (value != zero || ((u8 *)record)[0x24] != 0) {
        first = func_004973E0(record + 0xA, ((u8 *)record)[0x24]) != zero;
        second = func_004973E0(record + 0xE, 0) != zero;
        if ((second | first) != 0) {
            func_0049FBF0(index);
        }
        return;
    }

    if (record[0x14] == 0) {
        return;
    }
    func_00499CE0(record[0x14]);
    record[0x14] = 0;
    func_005054F8(index * 0x40 + 0x140004, 0);
}
