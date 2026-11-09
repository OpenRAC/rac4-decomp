#include "common.h"

extern void func_0071BE80(s32);
extern void func_L00_005BDB08(s32);
extern void func_L00_0071B478(s32);
extern void func_L00_0077C368(s32, void *);
extern u8 *D_002233A4;

void func_L00_00748B20(s32 arg0) {
    if ((*(u8 **)(D_002233A4 + 0x34))[0x28] == 0) {
        func_L00_0077C368(*(s32 *)(D_002233A4 + 0x68), D_002233A4);
    }
    func_L00_0071B478(arg0);
    func_0071BE80(arg0);
    func_L00_005BDB08(1);
}
