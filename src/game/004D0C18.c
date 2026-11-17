#include "common.h"

extern s32 func_0045E038(s32);
extern void func_004A1310(void *arg0);
extern void func_004A1358(void *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_00505B20(void);
extern u8 D_003D95C8[];
extern s32 D_2219A0;
extern u8 D_31A960[];

// Starts the active record's action when its counter allows, plays the matching sound and flags it.
void func_004D0C18(s32 arg0) {
    u8 *rec;
    u8 *q;
    u8 *p;
    u8 *e;
    s32 handle;

    rec = D_31A960 + func_00505B20() * 0x1A4;
    q = rec + 0x138;
    if (*(s32 *)(q + 0x50) >= 2) {
        if (arg0 != 0) {
            func_004A1358(q);
        } else {
            func_004A1310(q);
        }
        p = rec + 0x138;
        e = D_003D95C8 + *(s32 *)(p + 0x54) * 0x78;
        if (e[4] == 0) {
            handle = func_004A1A60(&D_2219A0, 0xF);
            func_00505238(handle, func_0045E038(*(s32 *)(D_003D95C8 + *(s32 *)(p + 0x54) * 0x78 + 0x10)));
        } else {
            handle = func_004A1A60(&D_2219A0, 0xF);
            func_00505238(handle, func_0045E038(0x16F));
        }
        func_004E21D8(0, 0, 0);
        func_004E0858();
        *(s32 *)(rec + 8) |= 6;
    }
}
