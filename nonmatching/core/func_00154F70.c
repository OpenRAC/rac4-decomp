/* Not matching yet: SIZE ours 204 / retail 200 (tools/try_func.py func_00154F70 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad1[0x4];
    s32 f1C;
    u8 pad2[0x48];
} Type3;

typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad1[0x14];
    s32 f44;
    u8 pad2[0x14];
    s32 f5C;
    u8 pad3[0x468];
    Type3 f4C8[1];
} Type2;

extern Type2 D_1BCC28;
extern void func_00126BE0(s32, s32);
extern void func_00126BC0(s32);

s32 func_00154F70(s32 arg0) {
    s32 temp_a1 = arg0 - 1;
    Type3 *entry;

    if ((D_1BCC28.f44 < temp_a1) || (temp_a1 < 0)) {
        return 0x80000004;
    }
    entry = &D_1BCC28.f4C8[temp_a1];
    func_00126BE0(D_1BCC28.f2C, temp_a1);
    if ((entry->f14 != 0) && (entry->f14 == arg0)) {
        D_1BCC28.f5C--;
        entry->f14 = 0;
    }
    if (entry->f1C == 4) {
        entry->f1C = 1;
    }
    func_00126BC0(D_1BCC28.f2C);
    return 0;
}
