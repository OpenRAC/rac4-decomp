#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4A98();
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern int D_002217E0[];
extern u8 *D_002233A4;
extern s32 D_172160[];
extern char func_0015CFC0[];

// Runs a request loop on the shared object until done or failed; returns 1 on success, else 0.
s32 func_L00_007692B0(u8 *arg0, s32 arg1) {
    s32 buf[12];
    s32 r;
    u8 *obj = D_002233A4;
    void *name = *(void **)(obj + 0x64);
    s32 v;

    *(u16 *)buf = *(u16 *)D_002217E0;
    func_0011A9EC((u8 *)buf + 0x15, name);
    buf[10] = arg1;
    buf[11] = *(s32 *)arg0;
    arg0[0xC8] = 1;
    obj[0] = 1;
    *(s32 *)(obj + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4A98(buf, func_0015CFC0, 0));
    r = 1;
    while (arg0[0xC8] != 0) {
        if (func_0015B558() != 0 || D_172160[0xB1] != 0) {
            *(s32 *)(obj + 0x10) = 0x1C;
            if (*(s32 *)(obj + 0x14) == 0) {
                *(s32 *)(obj + 0x14) = 0x1C;
            }
            r = 0;
            break;
        }
        obj[0x1C] = 1;
        func_0015A050();
        obj[0x1C] = 0;
        if (func_L00_00774650(obj, 1) == 0) {
            r = 0;
            break;
        }
    }
    obj[0] = 0;
    arg0[0xC8] = 0;
    if (r != 0) {
        v = *(s32 *)(arg0 + 0xCC);
        if (v == -0x3DE) {
            v = 0x23;
        } else if (v != 0) {
            v = 0x1C;
        } else {
            return r;
        }
        *(s32 *)(obj + 0x10) = v;
        if (*(s32 *)(obj + 0x14) == 0) {
            *(s32 *)(obj + 0x14) = v;
        }
        r = 0;
    }
    return r;
}
