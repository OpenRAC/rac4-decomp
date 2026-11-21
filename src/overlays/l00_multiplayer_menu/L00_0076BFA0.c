#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_00146D10(void);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4918(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_002217E0[];
extern u8 *D_002233A4;
extern u8 D_172160[];
extern u8 func_0015CCC8[];

// Runs a request on the shared object until the flag at +0xF0 clears or a failure is flagged; returns the embedded record at +0xF4 on success, else 0.
u8 *func_L00_0076BFA0(u8 *arg0, s32 arg1) {
    s32 buf[20];
    s32 r;
    u8 *s0 = D_002233A4;
    u8 *rec;
    u8 *d;
    void *name = *(void **)(s0 + 0x64);

    if (*(s32 *)arg0 == -1) {
        return 0;
    }
    *(u16 *)buf = D_002217E0[0];
    func_0011A9EC((u8 *)buf + 0x15, name);
    buf[10] = func_00146D10();
    func_L00_005C1758((s32)buf + 0x2C, arg1, 0x20);
    arg0[0xF0] = 1;
    s0[0] = 1;
    *(s32 *)(s0 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4918((u8 *)buf, (s32)func_0015CCC8, 0));
    d = D_172160;
    r = 1;
    rec = arg0 + 0xF4;
    while (arg0[0xF0] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(d + 0x2C4) != 0) {
            *(s32 *)(s0 + 0x10) = 0x26;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x26;
            }
            r = 0;
            break;
        }
        s0[0x1C] = 1;
        func_0015A050();
        s0[0x1C] = 0;
        if (func_L00_00774650(s0, 1) == 0) {
            r = 0;
            break;
        }
    }
    s0[0] = 0;
    arg0[0xF0] = 0;
    if (r != 0 && *(s32 *)(arg0 + 0x10C) != 0) {
        *(s32 *)(s0 + 0x10) = 0x26;
        if (*(s32 *)(s0 + 0x14) == 0) {
            *(s32 *)(s0 + 0x14) = 0x26;
        }
        r = 0;
    }
    return r != 0 ? rec : 0;
}
