#include "common.h"

extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049C248(s32 a, s32 b);
extern void func_0049C328(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004C33D0(void);
extern void func_004C3988(void);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 D_00221888;
extern u8 D_0030B7F8[];

void func_004C3EF8(void) {
    s32 index = func_00505B20();
    u8 *entry = D_0030B7F8 + index * 0x74;
    s32 type;
    func_0049C328(index, 0, 1);
    func_0049C328(index, 1, 1);
    func_0049C248(index, 2);
    func_0049C248(index, 3);
    type = *(s32 *)(entry + 0x10);
    switch (type) {
    case 1:
        func_004C3988();
        func_00505238(func_004A1A60(&D_00221888, 0x51), (const char *)func_0045E038(0x304F));
        break;
    case 2:
        func_004C33D0();
        func_00505238(func_004A1A60(&D_00221888, 0x50), (const char *)func_0045E038(0x304E));
        break;
    }
    func_00497980(8);
    *(s32 *)entry = 1;
    *(s32 *)(entry + 8) |= 0x80;
}
