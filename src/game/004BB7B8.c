#include "common.h"

extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_004BB958(void);
extern s32 func_00505B20(void);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);
extern s32 func_0054AB78(s32 arg0);
extern void func_004BB920(s32);
extern s32 D_0021DE10;
extern s32 D_0021F198;
extern s32 D_0021F930;
extern u8 D_0030A6F0[];

/* Validates the current player's selected entry and shows a message dialog. */
void func_004BB7B8(void)
{
    s32 id;
    u8 *p;
    u8 *e;
    u8 *s;
    s32 idx;
    s32 changed;
    s32 msg;
    s32 r;

    id = func_00505B20();
    p = D_0030A6F0 + id * 0x534;
    p += 0x4C8;
    if (*(s32 *)(p + 0x50) > 0) {
        idx = *(s32 *)(p + 0x54);
        e = 0;
        if (idx >= 0) {
            e = *(u8 **)(p + 0x34) + idx * 0x18;
        }
        s = *(u8 **)(e + 8);
        if (*s == 0) {
            r = func_0054AB78(D_0021F930);
            r = func_0054AB08(r, *(s32 *)(s + 4));
            e = func_0054A998(r);
            changed = D_0021F198 != *(s32 *)(s + 4);
            if (func_0054AB78(*(s32 *)e) != D_0021DE10 % 20) {
                func_00497980(7);
                msg = 0x3056;
            } else if (changed) {
                if (D_0021F198 == -1) {
                    func_004BB958();
                    return;
                }
                func_00497980(7);
                msg = 0x3057;
            } else {
                func_00497980(7);
                msg = 0x305B;
            }
            func_0049E790(id, (const char *)func_0045E038(msg), func_004BB920, 3, 0, 0, 0, -1.0f);
        } else {
            func_00497980(4);
        }
    }
}
