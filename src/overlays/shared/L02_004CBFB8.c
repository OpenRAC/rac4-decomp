#include "common.h"

extern s32 func_L00_005BC9B8(void *p);
extern s32 func_L00_005C9F50(s32);
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L00_00764E68(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_L01_00585BB0(u8 *object);
extern s32 func_L01_00585D40();
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L02_004CC170(void *p);
extern void func_00587E08(s32, s32, s16);
extern s32 D_0021DDB4;
extern s32 D_0021DE10;
extern s32 D_0021EA98;
extern u16 D_001F6788[];
extern s32 D_0021E6F4;
extern s32 D_0021E6F8;

// Per-frame update of one object: runs its timer and state checks on the linked
// block (+0xAC), then reports its counters through func_L00_00764E68 and func_00587E08.
void func_L02_004CBFB8(void *arg0) {
    u8 *s1;
    s16 v;

    if (D_0021DDB4 != 2 && func_L01_00585D40() == 0) {
        if (((u8 *)arg0)[0x20] == 0) {
            func_L02_004CC170(arg0);
        }
        s1 = *(u8 **)((u8 *)arg0 + 0xAC);
        if (((u8 *)arg0)[0x20] == 1) {
            if (D_0021DE10 != 2 || D_0021EA98 != 4 || D_001F6788[0] != 0) {
                if (func_L00_005BC9B8(s1 + 0x84) != 0) {
                    func_L00_0066D220(1, 0x130, arg0);
                } else {
                    v = *(s16 *)(s1 + 0x84);
                    if ((*(s16 *)(s1 + 0x86) * 0x3C >= v && v % 60 == 0) || v % 3600 == 0) {
                        func_L00_0066D220(0, 0x130, arg0);
                    }
                }
            }
            if (func_L01_00585BB0((u8 *)arg0) != 0) {
                func_L01_00591BD8((u8 *)arg0, 2, -1);
            }
        }
        func_L00_00764E68(0, func_L00_005C9F50(0x255C), s1[0x89], s1[0x8A]);
        func_00587E08(0, func_L00_005C9F50(0x255D), *(s16 *)(s1 + 0x84));
        if (D_0021E6F4 == 0 && D_0021E6F8 == 1) {
            func_L00_00764E68(1, func_L00_005C9F50(0x255C), s1[0x89], s1[0x8A]);
            func_00587E08(1, func_L00_005C9F50(0x255D), *(s16 *)(s1 + 0x84));
        }
    }
}
