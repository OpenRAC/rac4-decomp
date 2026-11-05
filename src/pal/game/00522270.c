#include "common.h"
typedef struct Player {
    u8 p0[0xB8];
    f32 angle;
    u8 pBC[0x5F4 - 0xBC];
    s16 grounded;
    u8 p5F6;
    u8 direction;
    u8 p5F8[0x1790 - 0x5F8];
    f32 target[4];
    f32 targetAngle;
    u8 p17A4[0x1AE0 - 0x17A4];
    s32 mode;
    u8 p1AE4[0x25CC - 0x1AE4];
    s32 action;
    u8 p25D0[0x2659 - 0x25D0];
    u8 relative;
    u8 p265A[0x2F00 - 0x265A];
    void *controller;
} Player;
extern s32 func_00490330(u32, s32, s32 *, void *);
extern s32 func_005167E8(Player *);
extern void func_0051C2E8(Player *, s32, f32);
extern f32 func_00520DF8(Player *, const f32 *, s32);
extern f32 func_00454370(f32, f32);
extern f32 func_00454410(f32, f32);
s32 func_00522270(Player *p)
{
    s32 result = 2;
    f32 angle;
    if (p->grounded == 0) {
        if (p->mode != 1 || !func_00490330(0x28, 2, NULL, p->controller) || func_005167E8(p) == 1 || func_005167E8(p) == 15)
            goto from_angle;
    }
    if (p->action == 16)
        goto from_angle;
    if (p->direction == 0)
        result = 0;
    else if (p->direction == 3)
        result = -1;
    else
        result = p->direction == 2 ? 2 : 1;
    goto done;
from_angle:
    func_0051C2E8(p, 0, 1.0f);
    if (p->relative)
        angle = func_00520DF8(p, p->target, 0);
    else
        angle = func_00454370(p->targetAngle, p->angle);
    if (func_00454410(angle, 3.1415927410125732f) < 0.7853981852531433f)
        result = -1;
    else if (func_00454410(angle, -1.5707963705062866f) < 0.7853981852531433f)
        result = 1;
    else if (func_00454410(angle, 1.5707963705062866f) < 0.7853981852531433f)
        result = 0;
done:
    return result;
}
