#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4E18(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00769DE0(void *);
extern s32 func_L00_00774650(void *, s32);
extern u16 D_002217E0[];
extern void *D_002233A4;
extern u8 D_172160[];
extern void func_0015CFE8(void);

/* Starts a request on arg0 and polls it until it completes, returning the result code. */
s32 func_L00_007683F8(u8 *arg0, s32 arg1) {
    u8 sp[0xF0];
    u8 *s2;
    u8 *s0;
    u8 *tab;
    void *a1v;
    s32 s4;
    s32 one;
    s32 v;
    s32 v1;

    s2 = D_002233A4;
    a1v = *(void **)(s2 + 0x64);
    *(u16 *)sp = D_002217E0[0];
    func_0011A9EC(sp + 0x15, a1v);
    s0 = sp + 0x26;
    func_0011A518(s0, 0, 0xC8);
    func_L00_005C1758((s32)s0, arg1, 0xC8);
    arg0[0x78] = 1;
    s2[0] = 1;
    *(s32 *)(s2 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4E18(sp, (s32)func_0015CFE8, 0));
    tab = D_172160;
    s4 = 1;
    one = 1;
    while (arg0[0x78] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tab + 0x2C4) != 0) {
            *(s32 *)(s2 + 0x10) = 0x1D;
            if (*(s32 *)(s2 + 0x14) == 0) {
                *(s32 *)(s2 + 0x14) = 0x1D;
            }
            s4 = 0;
            break;
        }
        s2[0x1C] = one;
        func_0015A050();
        s2[0x1C] = 0;
        if (func_L00_00774650(s2, 1) != 0) {
            continue;
        }
        s4 = 0;
        break;
    }
    s2[0] = 0;
    arg0[0x78] = 0;
    if (s4 != 0) {
        v = *(s32 *)(arg0 + 0x7C);
        if (v == -0x3DE) {
            v1 = 0x23;
        } else if (v != 0) {
            v1 = 0x1D;
        } else {
            goto done;
        }
        *(s32 *)(s2 + 0x10) = v1;
        if (*(s32 *)(s2 + 0x14) == 0) {
            *(s32 *)(s2 + 0x14) = v1;
        }
        s4 = 0;
done:
        if (s4 != 0 && arg0[0x408] != 0 && arg0[0x410] == 0) {
            s4 = func_L00_00769DE0(arg0);
        }
    }
    return s4;
}
