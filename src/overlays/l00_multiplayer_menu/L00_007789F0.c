#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED6FC8(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_00774650(void *, s32);
extern void func_0015D380(void);
extern u16 D_00221880[];
extern u8 *D_002233A4;
extern u8 D_172160[];

// Starts the setup calls for arg0 and waits in a loop until its state clears; returns the entry or NULL.
void *func_L00_007789F0(u8 *arg0, s32 arg1) {
    u8 tmp[0x30];
    u8 *obj;
    u8 *state;
    u8 *r;
    void *p;
    s64 s3;

    s3 = 1;
    obj = D_002233A4;
    p = *(void **)(obj + 0x64);
    *(u16 *)tmp = D_00221880[0];
    func_0011A9EC(tmp + 0x15, p);
    *(s32 *)(tmp + 0x28) = arg1;
    arg0[0xF4] = 1;
    obj[0] = 1;
    *(s32 *)(obj + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6FC8(tmp, (s32)func_0015D380, 0));
    state = D_172160;
    while (arg0[0xF4] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(state + 0x2C4) != 0) {
            *(s32 *)(obj + 0x10) = 0x54;
            if (*(s32 *)(obj + 0x14) == 0) {
                *(s32 *)(obj + 0x14) = 0x54;
            }
            s3 = 0;
            break;
        }
        obj[0x1C] = 1;
        func_0015A050();
        obj[0x1C] = 0;
        if (func_L00_00774650(obj, 1) == 0) {
            s3 = 0;
            break;
        }
    }
    obj[0] = 0;
    r = NULL;
    arg0[0xF4] = 0;
    if (s3 != 0) {
        r = *(s32 *)(arg0 + 0x110) != 0 ? NULL : arg0 + 0xF8;
    }
    return r;
}
