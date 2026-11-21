#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED6478(void *, void *, s32);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_002217B8[];
extern void *D_002233A4;
extern s32 D_172160[];
extern s32 D_00172194[];
extern void func_0015CC00(void);

/* Fills the local header, waits for the menu state, then copies the pending value into the shared slot */
s32 func_L00_00765BF0(u8 *arg0, char *arg1, s32 arg2) {
    u8 buf[0x70];
    u8 *s0;
    u8 *s1;
    u8 *s3;
    s32 s5;
    s32 v;

    s1 = arg0 + 4;
    s3 = (u8 *)D_002233A4;
    func_0011AFC8((char *)s1, arg1, 0x20);
    arg0[0x23] = 0;
    *(u16 *)buf = D_002217B8[0];
    func_0011A9EC(buf + 0x15, *(void **)(s3 + 0x64));
    func_L00_005C1758((s32)(buf + 0x26), (s32)s1, func_0011AB04(s1));
    func_L00_005C1758((s32)(buf + 0x46), arg2, 0x20);
    arg0[0x2C] = 1;
    s3[0] = 1;
    *(s32 *)(s3 + 0x8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6478(buf, (void *)func_0015CC00, 0));
    s0 = (u8 *)D_172160;
    s5 = 1;
    while (arg0[0x2C] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(s0 + 0x2C4) != 0) {
            *(s32 *)(s3 + 0x10) = 9;
            if (*(s32 *)(s3 + 0x14) == 0) {
                *(s32 *)(s3 + 0x14) = 9;
            }
            s5 = 0;
            break;
        }
        s3[0x1C] = 1;
        func_0015A050();
        s3[0x1C] = 0;
        if (func_L00_00774650(s3, 1) == 0) {
            s5 = 0;
            break;
        }
    }
    s3[0] = 0;
    arg0[0x2C] = 0;
    if (s5 != 0) {
        if (*(s32 *)(arg0 + 0x68) != 0) {
            *(s32 *)(s3 + 0x10) = 9;
            if (*(s32 *)(s3 + 0x14) == 0) {
                *(s32 *)(s3 + 0x14) = 9;
            }
            s5 = 0;
        }
        if (s5 != 0) {
            v = *(s32 *)(arg0 + 0x6C);
            *(s32 *)arg0 = v;
            D_00172194[0] = v;
            *(s32 *)(s3 + 0x10) = 0;
            *(s32 *)(s3 + 0x14) = 0;
        }
    }
    return s5;
}
