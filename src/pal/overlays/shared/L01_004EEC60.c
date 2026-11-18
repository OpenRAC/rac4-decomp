#include "common.h"

extern s32 func_L01_004E9EF0(u8 *, u8 *);
extern void func_L01_004F2DC8(s32);
extern s32 func_001633D8(void);
extern void func_L01_004F1D78(s32);
extern void func_L01_006B7330(s32, u8 *, s32, void *);
extern void func_L01_004EB7A8(u8 *, u8 *);
extern u8 D_003AB940[];

// moby update
void func_L01_004EEC60(u8 *moby) {
    u8 *pv;
    s32 owner;
    s32 r;

    pv = *(u8 **)(moby + 0xAC);
    owner = *(s32 *)(pv + 0x2E0);
    if (func_L01_004E9EF0(moby, pv) != 0) {
        func_L01_004F2DC8(*(s32 *)(pv + 0x2F4));
    }
    if (moby[0x67] == 9) {
        if (*(s32 *)(pv + 0x2F4) != 0) {
            r = func_001633D8();
            if (r == r / 4 * 4) {
                func_L01_004F1D78(*(s32 *)(pv + 0x2F4));
            } else {
                func_L01_006B7330(owner, moby, 9, D_003AB940);
            }
        } else {
            func_L01_006B7330(owner, moby, 9, D_003AB940);
        }
    }
    func_L01_004EB7A8(moby, pv);
}
