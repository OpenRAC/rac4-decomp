/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_01EA95C0(s32*);
extern s32 func_01EB60B8(s32 *arg0);
extern void func_01EB61E0(void *arg0);
extern s32 func_01EC21C8(void *arg0);
extern s32 D_001681A0[];

// Tears down the object at arg0: its sub-records (0x90 bytes each) and its attached cache.
void func_01EBDCA8(s32 *arg0) {
    s32 loc;
    s32 *ent;
    s32 *first;
    s32 var_s1 = 0;

    loc = (s32)arg0;
    if (loc != 0) {
        if (*(s32 *)loc != 0) {
            func_01EC21C8((void *)loc);
        }
        if (D_001681A0[0] != 0) {
            ((void (*)(s32))((s32 *)D_001681A0[0])[0x17])(-1);
            ((void (*)(s32))((s32 *)D_001681A0[0])[0x18])(-1);
        }
        first = *(s32 **)((u8 *)loc + 8);
        if (first != 0) {
            ent = first;
            if (*(u32 *)((u8 *)loc + 0x60) != 0) {
                do {
                    if (ent[0] != 0) {
                        func_01EB61E0((u8 *)ent + 0x14);
                        func_01EB61E0((u8 *)ent + 0x24);
                        func_01EA95C0((s32 *)((u8 *)ent + 0x84));
                        if (D_001681A0[0] != 0) {
                            ((void (*)(s32, s32))((s32 *)D_001681A0[0])[0x14])(-1, ent[0x1D]);
                        }
                        func_0011A518(ent, 0, 0x90);
                    }
                    var_s1++;
                    ent = (s32 *)((u8 *)ent + 0x90);
                } while (var_s1 < *(u32 *)((u8 *)loc + 0x60));
            }
            func_01EA95C0((s32 *)((u8 *)loc + 8));
        }
        if (*(s32 *)((u8 *)loc + 0x44) != 0) {
            func_01EB61E0((u8 *)loc + 0x3C);
        }
        func_01EB61E0((u8 *)loc + 0x2C);
        func_01EB60B8((s32 *)((u8 *)loc + 0x14));
        func_01EA95C0(&loc);
    }
}
