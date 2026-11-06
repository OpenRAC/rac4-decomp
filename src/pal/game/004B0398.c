/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"
extern s32 func_00506BB8(void);
extern s32 func_00498468(u32);
extern s32 func_005026A8(void *, s32, s32);
extern s32 func_00506C08(s32, s32);
extern s32 func_004A2798(void *, s32);
extern u32 func_004996F8(s32, s32);
extern s32 func_005063C0(s32, u32);
extern s32 func_004A1720(s32);
extern s32 func_005052D0(s32, f32, f32);
extern s32 func_00506978(s32, f32, f32);
extern s32 func_005060D8(u32, s32);
extern s32 func_00505F00(s32, u32, s32);
extern s32 func_005064A8(u32, f32);
extern s32 func_00506E68(s32, s32);
extern s32 D_002217B0;
#include "pal/record_003093A0.h"
/* Configures two entries for the selected player and attaches the second. */
s32 func_004B0398(void) {
    s32 player = func_00506BB8();
    s32 item;
    s32 parent;
    switch (func_00498468(func_00506BB8())) {
    case 0: case 2:
        func_005026A8(&D_002217B0, 13, -1);
        D_003093A0[player].word_58 = 2;
        break;
    case 1: case 3: case 4:
        func_005026A8(&D_002217B0, 14, -1);
        D_003093A0[player].word_58 = 0;
        break;
    }
    func_00506C08(6, D_002217B0);
    item = func_004A2798(&D_002217B0, 6);
    func_005063C0(item, func_004996F8(player, 1));
    func_004A1720(func_004A2798(&D_002217B0, 100));
    func_005052D0(func_004A2798(&D_002217B0, 100), 0.128f, 0.74f);
    func_00506978(func_004A2798(&D_002217B0, 100), 1.0f, 1.0f);
    func_005063C0(func_004A2798(&D_002217B0, 100), 0x80D0D0D0u);
    func_005060D8(func_004A2798(&D_002217B0, 100), 1);
    func_00505F00(func_004A2798(&D_002217B0, 100), 3, 2);
    func_005064A8(func_004A2798(&D_002217B0, 100), 0.0f);
    parent = D_002217B0;
    return func_00506E68(parent, func_004A2798(&D_002217B0, 100));
}
