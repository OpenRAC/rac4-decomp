#include "common.h"

void func_00669908(void);
void func_00669A28(void);
void func_00669AA8(void);
void func_00679210(u32 a0, u64 a1, s32 a2);

extern s32 D_001DFCF8[];
#define D_1DFCF8 (D_001DFCF8[0])

void func_L00_005B2DB8(void) {
    func_00669A28();
    func_00669908();
    func_00669AA8();
    func_00679210(0x47U, 0x5360BU, 0);
    func_00679210(0x4EU, 0x01000000 | ((s32) D_1DFCF8 >> 0xD), 0);
}
