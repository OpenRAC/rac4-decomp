/* cflags: @ee296 -O2 -G0 -falign-loops=1 -mno-split-addresses */
#include "common.h"

extern void func_01EF382C(void *);
extern void func_01EF60C8(void *);
extern s32 func_01EF308C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EF3164(s32, void *, void *);
extern s32 func_01EF328C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EE3A18(void *arg0, const u8 *arg1);
extern s32 D_0016E560[];
extern s32 D_00170118[];
extern s32 D_0019CAA0[];
extern s32 D_0019CAB0[];
extern s32 D_0019CAC0[];
extern s32 D_0019CAC8[];

/* Sets up the record at arg0 (the D_00170118 pointer and four lookups), then fills up to four entries from D_0016E560. */
s32 func_01EF612C(s32 *arg0) {
    s32 i;

    func_01EF382C(arg0);
    arg0[0xB0 / 4] = (s32)D_00170118;
    func_01EF60C8(arg0);
    func_01EF308C(arg0[0], (s32)D_0019CAA0, &arg0[0xB8 / 4]);
    func_01EF308C(arg0[0], (s32)D_0019CAB0, &arg0[0xBC / 4]);
    func_01EF3164(arg0[0], D_0019CAC0, &arg0[0xB4 / 4]);
    arg0[0xA0 / 4] = func_01EE3A18((void *)arg0[0], (const u8 *)D_0019CAC8);
    for (i = 0; i < 4; i++) {
        if (func_01EF328C(arg0[0], D_0016E560[i], &arg0[0xC0 / 4 + i]) == 0) {
            break;
        }
    }
}
