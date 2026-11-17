#include "common.h"

extern s32 func_L00_0071B550();
extern void func_L00_0071BA48(void *, u32);
extern void func_L00_007495A8();
extern void func_L00_00753170();
extern s32 func_L00_007647B0(s32 identifier);
extern void *D_00220D14;

/* handles a menu command code: scroll, select or fall through to the default handler */
s32 func_L00_00749250(void *arg0, s32 arg1) {
    u8 *p = (u8 *)arg0;
    func_L00_00753170(1, 0, 0x190, 0, 0x82);
    if (arg1 == 1) {
        func_L00_007495A8(arg0, -1);
        return 1;
    }
    if (arg1 == 2) {
        func_L00_007495A8(arg0, 1);
        return 1;
    }
    if (arg1 == 7) {
        if (*(u8 *)(p + 0x674) != 0) {
            func_L00_007647B0(0xBB);
        }
        *(s32 *)((u8 *)D_00220D14 + 0x118) = 0x2A;
        return 1;
    }
    if (arg1 == 5) {
        if (*(u8 *)(p + 0x674) != 0) {
            func_L00_007647B0(0xBC);
        }
        *(u8 *)(p + 0x66C) = 1;
    }
    if (func_L00_0071B550(arg0, arg1) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x230) != -1) {
        void *o = *(void **)((u32)p + (*(s32 *)(p + 0x230) << 2) + 0xB0);
        func_L00_0071BA48(arg0, (*(s32 (**)(void *))(*(u8 **)((u8 *)o + 0x58) + 0x44))(o));
    } else {
        func_L00_0071BA48(arg0, 0xFFFFFFFF);
    }
    *(s32 *)(p + 0x670) = *(s32 *)(p + 0x230);
    return 0;
}
