/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_01EED528(s32 arg0);
extern void func_01F0C090(const char *, s32);
extern s32 D_0019E7A8;
extern s32 D_0019E7B8;
extern s32 D_0019E7F0;

/* Runs the buffer-filling step on arg0 with the two checks, then returns the shared record at D_0019E7F0. */
void *func_01F0BFDC(s32 arg0) {
    s8 buf[0xC0];
    u8 *rec;

    if (arg0 == 0) {
        func_01EED528(0x23);
        func_01F0C090((const char *)&D_0019E7A8, 0x69);
    }
    rec = (u8 *)&D_0019E7F0;
    if (func_0011D920(buf, (s8 *)&D_0019E7B8, (s8 *)rec, arg0) >= 0xB1) {
        func_01F0C090((const char *)&D_0019E7A8, 0x73);
    }
    if (func_0011A8A0((void *)arg0, rec) != 0) {
        func_01EED528(0x23);
        func_01F0C090((const char *)&D_0019E7A8, 0x78);
    }
    return rec;
}
