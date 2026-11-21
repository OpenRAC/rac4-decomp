#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_1ED6E48(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_00774650(void *, s32);
extern void func_0015D100(void);
extern void *D_002233A4;
extern u16 D_00221808[];
extern u8 D_172160[];

/* Starts a request on arg0, polls it until it completes, then reports the record count through arg2. */
void *func_L00_0076FA90(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 sp[0x30];
    u8 *s1;
    u8 *tab;
    void *ret;
    s32 s3;
    s32 one;
    s32 v;
    s32 v1;

    s1 = D_002233A4;
    *(s32 *)(arg0 + 0x1B00) = 0;
    *(u16 *)sp = D_00221808[0];
    func_0011A9EC((char *)sp + 0x15, *(char **)(s1 + 0x64));
    *(s32 *)(sp + 0x28) = arg1;
    arg0[0x20] = 1;
    s1[0] = 1;
    *(s32 *)(s1 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_1ED6E48(sp, (s32)func_0015D100, 0));
    tab = D_172160;
    s3 = 1;
    one = 1;
    while (arg0[0x20] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tab + 0x2C4) != 0) {
            *(s32 *)(s1 + 0x10) = 0x39;
            if (*(s32 *)(s1 + 0x14) == 0) {
                *(s32 *)(s1 + 0x14) = 0x39;
            }
            s3 = 0;
        }
        s1[0x1C] = one;
        func_0015A050();
        s1[0x1C] = 0;
        if (func_L00_00774650(s1, 1) != 0) {
            continue;
        }
        s3 = 0;
        break;
    }
    s1[0] = 0;
    arg0[0x20] = 0;
    v = *(s32 *)(arg0 + 0x24);
    if (v == 1) {
        *(s32 *)(arg0 + 0x1B00) = 0;
    } else {
        if (v == -0x3DF || v == -0x3D1) {
            v1 = 0x3F;
        } else if (v < 0) {
            v1 = 0x39;
        } else {
            goto done;
        }
        *(s32 *)(s1 + 0x10) = v1;
        if (*(s32 *)(s1 + 0x14) == 0) {
            *(s32 *)(s1 + 0x14) = v1;
        }
        s3 = 0;
    }
done:
    ret = 0;
    *arg2 = 0;
    if (s3 != 0) {
        ret = arg0 + 0x1B04;
        *arg2 = *(s32 *)(arg0 + 0x1B00);
    }
    return ret;
}
