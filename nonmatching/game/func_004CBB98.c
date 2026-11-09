/* Not matching yet: BYTES 8/628 (tools/try_func.py func_004CBB98 --diff). Not part of the build. */
#include "common.h"

extern void func_00498C98(void *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004CC978(void);
extern void func_00504F68(s32, s32);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern void *func_00510BE8(s32 arg0);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 func_00548DA0();
extern s32 D_003D2738[];
extern s32 D_00221920;
extern u8 D_0030EAA0[];

void func_004CBB98(s32 arg0) {
    s32 buf[6];
    u8 *rec;
    u8 *pl;
    s32 h;
    s32 h2;
    s32 h3;

    rec = D_0030EAA0 + arg0 * 100;
    buf[0] = 5;
    buf[1] = *(s32 *)(rec + 0x38);
    func_00498C98(buf);
    func_00505328(func_004A1A60(&D_00221920, D_003D2738[8]), 0x80808080);
    func_005054F8(func_004A1A60(&D_00221920, D_003D2738[8]), buf[2]);
    func_00504F68(func_004A1A60(&D_00221920, D_003D2738[8]), 1);
    func_00505328(func_004A1A60(&D_00221920, D_003D2738[9]), 0x80808080);
    h = func_004A1A60(&D_00221920, D_003D2738[9]);
    func_005054F8(h, func_004CC978());
    func_00504F68(func_004A1A60(&D_00221920, D_003D2738[9]), 1);
    pl = func_00510BE8(arg0);
    if (func_00548DA0(*(s32 *)(pl + 0x26E4), 0x11) != 0) {
        func_00505328(func_004A1A60(&D_00221920, D_003D2738[10]), 0x80808080);
        h2 = func_004A1A60(&D_00221920, D_003D2738[10]);
        func_005054F8(h2, *(u16 *)((u8 *)func_00548D28(0x11, 0) + 0x36));
        func_00504F68(func_004A1A60(&D_00221920, D_003D2738[10]), 1);
    } else {
        func_00504F68(func_004A1A60(&D_00221920, D_003D2738[10]), 0);
    }
    if (func_00548DA0(*(s32 *)(pl + 0x26E4), 0x12) != 0) {
        func_00505328(func_004A1A60(&D_00221920, 0x33), 0x80808080);
        h3 = func_004A1A60(&D_00221920, 0x33);
        func_005054F8(h3, *(u16 *)((u8 *)func_00548D28(0x12, 0) + 0x36));
        func_00504F68(func_004A1A60(&D_00221920, 0x33), 1);
    } else {
        func_00504F68(func_004A1A60(&D_00221920, D_003D2738[11]), 0);
    }
}
