#include "common.h"

extern s32 D_0021DDB4;
extern s32 D_0021EDD4;
extern s32 D_2F32B8[];
extern void func_0047F768(s32 arg0, s32 arg1);
extern void func_00497D58(s32 index);
extern void func_004995F0(void);

// Runs the two calls for entry arg0 when its state is 2 and D_0021DDB4 is 3, then copies word 4 of the entry to word 0 and calls func_00497D58.
void func_00497E10(s32 arg0) {
    if (D_0021EDD4 != 1) {
        if (*(s32 *)((u8 *)D_2F32B8 + arg0 * 0x54) == 2 && D_0021DDB4 == 3) {
            func_004995F0();
            func_0047F768(0, 0);
        }
    }
    *(s32 *)((u8 *)D_2F32B8 + arg0 * 0x54) = *(s32 *)((u8 *)D_2F32B8 + arg0 * 0x54 + 4);
    func_00497D58(arg0);
}
