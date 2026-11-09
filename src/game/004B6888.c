#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad[0x1E4];
} Type1;

extern Type1 D_3098F0[];

extern s32 func_0045E038(s32);
extern void func_004A01F0(s32 arg0, s32 arg1);
extern void func_004B5DF8(s32 arg0);
extern void func_004B5E18(s32 arg0, s32 arg1, void (*arg2)(), s32 arg3);
extern void func_004B5E70(s32 arg0, void (*arg1)(), s32 arg2);
extern void func_004B6CA8();
extern void func_004B7238();
extern void func_004B7340();

void func_004B6888(s32 arg0) {
    func_004A01F0(arg0, D_3098F0[arg0].f10);
    func_004B5DF8(arg0);
    func_004B5E18(arg0, func_0045E038(0x1CF), func_004B7238, 1);
    func_004B5E18(arg0, func_0045E038(0x2387), func_004B7340, 1);
    func_004B5E18(arg0, func_0045E038(0x362D), func_004B6CA8, 1);
    func_004B5E70(arg0, func_004B6CA8, func_0045E038(0x106));
}
