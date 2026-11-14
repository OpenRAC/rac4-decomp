/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_01EE3A18(s32, void *);
extern void func_01F04A5C(void *, s32, u8 *, s32 *);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019E0F0[];
extern u8 D_0019E110[];
extern u8 D_0019E120[];
extern u8 D_0019E128[];
extern u8 D_0019E130[];

/* Looks up two entries for arg1 and reports to the log unless both are found and the status is 1. */
void func_01F049B8(void *arg0, s32 arg1) {
    s32 sp0;
    s32 temp_s1;
    s32 temp_v0;

    func_01F04A5C(arg0, arg1, D_0019E110, &sp0);
    if (sp0 == 1) {
        temp_s1 = func_01EE3A18(arg1, D_0019E120);
        temp_v0 = func_01EE3A18(arg1, D_0019E128);
        if ((temp_s1 != 0) && (temp_v0 != 0)) {
            func_0011A8A0(D_0019E130, (const u8 *) temp_s1);
            return;
        }
        func_01F0C090(D_0019E0F0, 0x42);
    }
}
