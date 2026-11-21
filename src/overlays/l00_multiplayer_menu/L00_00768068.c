#include "common.h"

extern s32 D_002233A4;
extern u16 D_002217E0[];
extern u8 D_172160[];
extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_0015CD40(void);
extern s32 func_01ED4898(u8 *obj, s32 arg1, s32 arg2);
extern int func_L00_00767A50(void *, int);
extern s32 func_L00_00774650(void *, s32);

/* Starts the setup exchange for the menu object, waits for the ready state, and then picks the result code. */
s32 func_L00_00768068(u8 *arg0) {
    u8 buf[0x30];
    s32 var_s1;
    s32 var_s0;
    s32 t;
    u8 *s0;
    u8 *s3;
    void *p;

    s0 = (u8 *)D_002233A4;
    p = *(void **)(s0 + 0x64);
    *(u16 *)buf = D_002217E0[0];
    func_0011A9EC(buf + 0x15, p);
    *(s32 *)(buf + 0x28) = *(s32 *)arg0;
    arg0[0x68] = 1;
    s0[0] = 1;
    *(s32 *)(s0 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4898(buf, (s32)func_0015CD40, 0));
    s3 = D_172160;
    var_s1 = 1;
    while (arg0[0x68] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(s3 + 0x2C4) != 0) {
            *(s32 *)(s0 + 0x10) = 0x16;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x16;
            }
            var_s1 = 0;
            break;
        }
        s0[0x1C] = 1;
        func_0015A050();
        s0[0x1C] = 0;
        if (func_L00_00774650(s0, 1) == 0) {
            var_s1 = 0;
            break;
        }
    }
    s0[0] = 0;
    arg0[0x68] = 0;
    if (var_s1 != 0) {
        t = *(s32 *)(arg0 + 0x6C);
        if (t == -0x3DE) {
            *(s32 *)(s0 + 0x10) = 0x23;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x23;
            }
            var_s1 = 0;
        } else if (t != 0) {
            *(s32 *)(s0 + 0x10) = 0x16;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x16;
            }
            var_s1 = 0;
        }
        if (var_s1 != 0) {
            var_s0 = 9;
            if (*(s32 *)arg0 != -1) {
                for (;;) {
                    var_s1 = func_L00_00767A50(arg0, 0);
                    if (var_s1 == 0) {
                        break;
                    }
                    var_s0 -= 1;
                    if (*(s32 *)arg0 == -1) {
                        break;
                    }
                    if (var_s0 == -1) {
                        break;
                    }
                }
            }
            var_s1 = (~*(s32 *)arg0 != 0) ? 0 : var_s1;
        }
    }
    return var_s1;
}
