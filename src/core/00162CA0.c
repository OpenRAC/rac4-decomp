#include "common.h"

extern s32 D_001A4EF8[];
extern s32 D_001A4F18[];
s32 func_0011A518(void *, s32, s32);
extern s32 func_0011D5D8(const char *, ...);
void func_00147BA8(void);
s32 func_0014D3E8(s32, s32);
s32 func_0014EB50(s32, void *);

// Initialize a request record: run func_00147BA8, clear the 0x18-byte block at
// +0x10 and fill +0x10, +0x18 and +0x1C (9). Submit it with func_0014EB50; a
// nonzero result is reported through func_0011D5D8 (D_001A4EF8) and gives 0.
// Otherwise run func_0014D3E8 (a nonzero result is reported through D_001A4F18)
// and return 8.
s32 func_00162CA0(void *request, s32 param_a, s32 param_b, s32 param_c) {
    void *buffer = (u8 *)request + 0x10;
    s32 value;
    func_00147BA8();
    func_0011A518(buffer, 0, 0x18);
    *(s32 *)((u8 *)request + 0x10) = param_a;
    *(s32 *)((u8 *)request + 0x18) = param_b;
    *(s16 *)((u8 *)request + 0x1C) = 9;
    value = func_0014EB50(*(s32 *)request, buffer);
    if (value != 0) {
        func_0011D5D8((const char *)D_001A4EF8, value);
        return 0;
    }
    value = func_0014D3E8(*(s32 *)request, param_c);
    if (value != 0) func_0011D5D8((const char *)D_001A4F18, value);
    return 8;
}
