#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004BAD50(s32 a0);
extern void func_004BAC90(s32 arg0);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 D_0021DE6C;
extern int D_003D95AC[];
extern s32 D_002217E0;
extern s8 D_0030A360[];
extern u8 D_0030A4E0[];

/* When arg0 is set, either opens a prompt built from string 0x50A or resets via func_004BAD50, then shows the D_0030A4E0 slot for D_0021DE6C. */
void func_004BA3B0(s32 arg0) {
    if (arg0 != 0) {
        if (D_0021DE6C == 0) {
            func_00497980(7);
            func_0011D920(D_0030A360, (s8 *)func_0045E038(0x50A), 0xF);
            func_0049E790(func_00505B20(), (const char *)D_0030A360, func_004BAC90, 3, 0, 0, 0, -1.0f);
        } else {
            func_004BAD50(0);
            func_00497980(0x10);
        }
    }
    func_00505238(func_004A1A60(&D_002217E0, D_003D95AC[0]), (const char *)(D_0021DE6C * 0x30 + D_0030A4E0));
}
