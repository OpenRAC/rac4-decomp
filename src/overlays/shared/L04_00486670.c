#include "common.h"

extern void func_L00_005BCAE0(void *, s32, s32);
extern void func_L00_005DD4A0(void *);
extern void func_L00_005DDDE8(void *, s32, void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 func_L04_00486770();
extern s32 D_222714;

/* Builds two entries from table ids, then enters state one. */
void func_L04_00486670(u8 *object) {
    u8 *state = *(u8 **)(object + 0xAC);
    s32 *ids;
    s32 *out;
    u8 *buf;
    u8 *e;
    s32 i;
    if (*(s32 *)state == -1 || (out = (s32 *)(state + 8), *(s32 *)(state + 4) == -1)) {
        func_L00_005DD4A0(object);
        return;
    }
    buf = state + 0x10;
    ids = (s32 *)state;
    i = 1;
    do {
        e = (u8 *)(D_222714 + (*ids << 8));
        ids++;
        func_L00_005BCAE0(buf, 0, 0x40);
        i--;
        func_L00_005DDDE8(e, 0, buf);
        buf += 0x40;
        *out = func_L04_00486770(e);
        out++;
    } while (i >= 0);
    *(s32 *)(state + 0x94) = 1;
    func_L01_00591BD8(object, 1, -1);
}
