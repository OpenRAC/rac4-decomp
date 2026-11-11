#include "common.h"

extern s32 D_00355320[];
extern void func_0054E910(void);
extern s32 func_00453CE8(void *);
extern void func_004F6150(f32);

s32 func_0054C250(s32 arg0) {
    s32 *record;
    s32 result = 0;
    s32 one = 1;
    func_0054E910();
    record = D_00355320;
    switch (record[0x14 / 4]) {
    case 0:
        if (func_00453CE8(record + 0x10 / 4) != 0) {
            record[0x14 / 4] = one;
            record[0x10 / 4] = 0x1E;
        }
        func_004F6150(1.0f);
        break;
    case 1:
        if (func_00453CE8(record + 0x10 / 4) != 0) {
            record[0x14 / 4] = 2;
            record[0x10 / 4] = 0x12C;
        }
        func_004F6150((f32)record[0x10 / 4] / 30.0f);
        break;
    case 2:
        if (func_00453CE8(record + 0x10 / 4) != 0) {
            record[0x14 / 4] = 3;
            record[0x10 / 4] = 0x1E;
        }
        func_004F6150(0.0f);
        break;
    case 3:
        if (arg0 != 0) {
            result = func_00453CE8(record + 0x10 / 4) ? one : 0;
        }
        func_004F6150(1.0f - (f32)record[0x10 / 4] / 30.0f);
        break;
    }
    return result;
}
