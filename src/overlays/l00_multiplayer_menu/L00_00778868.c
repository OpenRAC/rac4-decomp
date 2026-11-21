#include "common.h"

typedef struct {
    u16 f0;
    u8 pad2[0x16];
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    s32 f28;
    s32 f2C;
} Type2;

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED8278(void *, void *, s32);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern void func_0015D330(void);
extern u16 D_00221880[];
extern s32 D_172160[];
extern u8 *D_002233A4;

/* Runs a modal loop on the menu object until it finishes or a pad event aborts it. */
s32 func_L00_00778868(u8 *arg0) {
    Type2 sp;
    u8 *obj;
    s32 ret;

    sp.f0 = D_00221880[0];
    sp.f18 = 0xFFFFFFFFu;
    sp.f1C = 0xFFFFFFFFu;
    sp.f20 = 0xFFFFFFFFu;
    sp.f24 = 0xFFFFFFFFu;
    sp.f28 = 0;
    sp.f2C = 0x20;
    obj = D_002233A4;
    arg0[0xEC] = 1;
    obj[0] = 1;
    *(s32 *)(obj + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED8278(&sp, func_0015D330, 0));
    ret = 1;
    while (arg0[0xEC] != 0) {
        if (func_0015B558() != 0 || D_172160[0xB1] != 0) {
            *(s32 *)(obj + 0x10) = 0x51;
            if (*(s32 *)(obj + 0x14) == 0) {
                *(s32 *)(obj + 0x14) = 0x51;
            }
            ret = 0;
            break;
        }
        obj[0x1C] = 1;
        func_0015A050();
        obj[0x1C] = 0;
        if (func_L00_00774650(obj, 1) == 0) {
            ret = 0;
            break;
        }
    }
    obj[0] = 0;
    arg0[0xEC] = 0;
    if (ret != 0 && *(s32 *)(arg0 + 0xF0) != 0) {
        *(s32 *)(obj + 0x10) = 0x51;
        if (*(s32 *)(obj + 0x14) == 0) {
            *(s32 *)(obj + 0x14) = 0x51;
        }
        ret = 0;
    }
    return ret;
}
