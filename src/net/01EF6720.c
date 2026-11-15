/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

/* reads five values for the object from func_01EEE12C, storing each one its lookup finds */
extern s32 func_01EEE12C(void);
extern s32 func_01EF3164(s32, void *, void *);
extern s32 func_01EF339C(s32 a,void *b,void *out);
extern void func_01F0C090(const char *, s32);
extern char D_0019CB38[];
extern char D_0019CB50[];
extern char D_0019CB60[];
extern char D_0019CB70[];
extern char D_0019CB80[];
extern char D_0019CB90[];

void func_01EF6720(s32 *arg0) {
    s32 temp_s0;
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;

    temp_s0 = func_01EEE12C();
    if (temp_s0 == 0) {
        func_01F0C090(D_0019CB38, 0x82);
    }
    sp0 = 0;
    if (func_01EF3164(*arg0, D_0019CB50, &sp0) != 0) {
        *(f32 *)((u8 *)temp_s0 + 4) = *(f32 *)&sp0;
    }
    sp4 = 0;
    if (func_01EF3164(*arg0, D_0019CB60, &sp4) != 0) {
        *(f32 *)((u8 *)temp_s0 + 8) = *(f32 *)&sp4;
    }
    sp8 = 0;
    if (func_01EF3164(*arg0, D_0019CB70, &sp8) != 0) {
        *(f32 *)((u8 *)temp_s0 + 0xC) = *(f32 *)&sp8;
    }
    spC = 0;
    if (func_01EF3164(*arg0, D_0019CB80, &spC) != 0) {
        *(f32 *)((u8 *)temp_s0 + 0x10) = *(f32 *)&spC;
    }
    sp10 = 0;
    if (func_01EF339C(*arg0, D_0019CB90, &sp10) != 0) {
        *(s32 *)((u8 *)temp_s0 + 0x14) = sp10;
    }
}
