#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4C98(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern int func_L00_00767A50(void *, int);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_002217E0[];
extern u8 *D_002233A4;
extern u8 D_172160[];
extern u8 func_0015CF48[];

// Runs a request on the shared object until the flag at +0xB8 clears or a failure is flagged, then finishes it with func_L00_00767A50.
s32 func_L00_00769440(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[64];
    s32 r;
    u8 *s3 = D_002233A4;
    u8 *d;
    void *name = *(void **)(s3 + 0x64);

    *(u16 *)buf = D_002217E0[0];
    func_0011A9EC((u8 *)buf + 0x15, name);
    buf[10] = arg1;
    buf[11] = arg2;
    func_L00_005C1758((s32)buf + 0x30, arg3, 0xC8);
    arg0[0xB8] = 1;
    s3[0] = 1;
    *(s32 *)(s3 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4C98((u8 *)buf, (s32)func_0015CF48, 0));
    d = D_172160;
    r = 1;
    while (arg0[0xB8] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(d + 0x2C4) != 0) {
            *(s32 *)(s3 + 0x10) = 0x1B;
            if (*(s32 *)(s3 + 0x14) == 0) {
                *(s32 *)(s3 + 0x14) = 0x1B;
            }
            r = 0;
            break;
        }
        s3[0x1C] = 1;
        func_0015A050();
        s3[0x1C] = 0;
        if (func_L00_00774650(s3, 1) == 0) {
            r = 0;
            break;
        }
    }
    s3[0] = 0;
    arg0[0xB8] = 0;
    if (r != 0) {
        if (*(s32 *)(arg0 + 0xBC) != 0) {
            *(s32 *)(s3 + 0x10) = 0x19;
            if (*(s32 *)(s3 + 0x14) == 0) {
                *(s32 *)(s3 + 0x14) = 0x19;
            }
            r = 0;
        }
        if (r != 0) {
            r = func_L00_00767A50(arg0, 0);
        }
    }
    return r;
}
