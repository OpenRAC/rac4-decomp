#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7218(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_007665A0(u8 *p);
extern s32 func_L00_00766DD0(u8 *);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_002217D0[];
extern u8 *D_002233A4;
extern u8 D_172160[];
extern u8 func_0015CCA0[];

// Runs a request on the shared object until the owner's flag at +0x1C clears or a failure is flagged, then post-processes the result.
s32 func_L00_00766C20(u8 *arg0, s32 arg1) {
    s32 buf[12];
    s32 r;
    u8 *s1 = D_002233A4;
    u8 *d;
    void *name = *(void **)(s1 + 0x64);

    *(u16 *)buf = D_002217D0[0];
    func_0011A9EC((u8 *)buf + 0x15, name);
    buf[10] = arg1;
    arg0[0x1C] = 1;
    s1[0] = 1;
    *(s32 *)(s1 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED7218((u8 *)buf, (s32)func_0015CCA0, 0));
    d = D_172160;
    r = 1;
    while (arg0[0x1C] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(d + 0x2C4) != 0) {
            *(s32 *)(s1 + 0x10) = 0x13;
            if (*(s32 *)(s1 + 0x14) == 0) {
                *(s32 *)(s1 + 0x14) = 0x13;
            }
            r = 0;
            break;
        }
        s1[0x1C] = 1;
        func_0015A050();
        s1[0x1C] = 0;
        if (func_L00_00774650(s1, 1) == 0) {
            r = 0;
            break;
        }
    }
    s1[0] = 0;
    arg0[0x1C] = 0;
    if (r != 0) {
        s32 code = *(s32 *)(arg0 + 0x20);

        if (code == -0x3DD) {
            r = 0;
        } else if (code == -0x3DC) {
            *(s32 *)(s1 + 0x10) = 0x13;
            if (*(s32 *)(s1 + 0x14) == 0) {
                *(s32 *)(s1 + 0x14) = 0x13;
            }
        }
        if (r != 0) {
            r = func_L00_00766DD0(arg0);
            if (r != 0) {
                r = func_L00_007665A0(arg0);
            }
        }
    }
    return r;
}
