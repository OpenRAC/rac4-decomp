#include "common.h"

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00504F68(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);

void func_004C5DE8(s32 *arg0, s32 arg1, s32 arg2) {
    func_005054F8(func_004A1A60(arg0 + 1, 8), 0x7546);
    func_005054F8(func_004A1A60(arg0 + 1, 7), 0x7546);
    func_005054F8(func_004A1A60(arg0 + 1, 6), 0x7546);
    func_005054F8(func_004A1A60(arg0 + 1, 5), 0x7546);
    func_005054F8(func_004A1A60(arg0 + 1, 4), 0x7546);
    func_00504F68(func_004A1A60(arg0 + 1, 8), 0);
    func_00504F68(func_004A1A60(arg0 + 1, 7), 0);
    func_00504F68(func_004A1A60(arg0 + 1, 6), 0);
    func_00504F68(func_004A1A60(arg0 + 1, 5), 0);
    func_00504F68(func_004A1A60(arg0 + 1, 4), 0);
    if (arg1 != 0) {
        switch (arg2) {
        case 5:
            func_00504F68(func_004A1A60(arg0 + 1, 4), 1);
        case 4:
            func_00504F68(func_004A1A60(arg0 + 1, 5), 1);
        case 3:
            func_00504F68(func_004A1A60(arg0 + 1, 6), 1);
        case 2:
            func_00504F68(func_004A1A60(arg0 + 1, 7), 1);
        case 1:
            func_00504F68(func_004A1A60(arg0 + 1, 8), 1);
        }
    }
}
