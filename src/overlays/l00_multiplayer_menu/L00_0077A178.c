#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_00161AE8(void);
extern s32 func_01ED5F40(void *o);
extern s32 func_01ED5FE8(void *, s32);
extern void func_L00_00766DD0(void *);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern void func_L00_0077A2F8(void);
extern u8 D_172160[];
extern u8 *D_002233A4;
extern u8 D_0021DF99;

/* Per-frame step of the menu object: runs the busy loop and returns 1 while the step stays active. */
s32 func_L00_0077A178(void *arg0)
{
    s32 sp[4];
    u8 *obj = arg0;
    u8 *owner = D_002233A4;
    s32 result;

    if (D_172160[0x265] != 0) {
        func_00161AE8();
        D_172160[0x265] = 0;
    }
    if (D_0021DF99 != 0) {
        func_L00_00766DD0(*(void **)(owner + 0x38));
    }
    func_01ED5F40(sp);
    sp[0] = *(s32 *)(D_172160 + 0xC);
    sp[2] = (s32)func_L00_0077A2F8;
    obj[0x175] = 1;
    owner[0] = 1;
    *(s32 *)(owner + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED5FE8(sp, 0));
    result = 1;
    for (;;) {
        u8 *t = D_172160;
        if (obj[0x175] == 0) {
            break;
        }
        if (func_0015B558() != 0 || *(s32 *)(t + 0x2C4) != 0) {
            *(s32 *)(owner + 0x10) = 0x5B;
            if (*(s32 *)(owner + 0x14) == 0) {
                *(s32 *)(owner + 0x14) = 0x5B;
            }
            result = 0;
            break;
        }
        owner[0x1C] = 1;
        func_0015A050();
        owner[0x1C] = 0;
        if (func_L00_00774650(owner, 0) == 0) {
            result = 0;
            break;
        }
    }
    owner[0] = 0;
    *(u8 *)(*(u8 **)(owner + 0x38) + 8) = 0;
    obj[0x175] = 0;
    D_172160[0x2D5] = 0;
    obj[0x11E] = 0;
    return result;
}
