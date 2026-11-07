/* Not matching yet: BYTES 23/356 (tools/try_func.py func_004B65D8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad[0x1E4];
} Type1;

extern Type1 D_003098F0[];
extern s32 D_0021DE10;

extern s32 func_0045E038(s32);
extern void func_004A01F0(s32 arg0, s32 arg1);
extern void func_004B5DF8(s32 arg0);
extern void func_004B5E18(s32 arg0, s32 arg1, void (*arg2)(), s32 arg3);
extern void func_004B5E70(s32 arg0, void (*arg1)(), s32 arg2);
extern void func_004B6C00();
extern void func_004B7290();
extern void func_004B7398();
extern void func_004B73F0();
extern void func_004B7448();
extern void func_004B74A0();
extern void func_004B74F8();

void func_004B65D8(s32 arg0) {
    s32 t;
    s32 v;

    func_004A01F0(arg0, D_003098F0[arg0].f8);
    func_004B5DF8(arg0);
    t = func_0045E038(0x2383);
    func_004B5E18(arg0, t, func_004B73F0, (D_0021DE10 == 0xF) ? 0 : (D_0021DE10 != 0x23));
    func_004B5E18(arg0, func_0045E038(0x3469), func_004B7290, 1);
    func_004B5E18(arg0, func_0045E038(0x31CE), func_004B74A0, 1);
    func_004B5E18(arg0, func_0045E038(0x1C1), func_004B7398, 1);
    func_004B5E18(arg0, func_0045E038(0x139E), func_004B7448, 1);
    func_004B5E18(arg0, func_0045E038(0x31CF), func_004B74F8, 1);
    func_004B5E18(arg0, func_0045E038(0x362D), func_004B6C00, 1);
    func_004B5E70(arg0, func_004B6C00, func_0045E038(0x237C));
}
