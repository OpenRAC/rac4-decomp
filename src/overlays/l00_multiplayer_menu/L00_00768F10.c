#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4B18(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_0076A658(void *);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_002217E0[];
extern void *D_002233A4;
extern s32 D_172160[];
extern char func_0015CF20[];

// Starts the request on the object's slot, polls it until done, then maps the state code.
s32 func_L00_00768F10(u8 *arg0, s32 arg1, s32 arg2) {
    s32 buf[62];
    s32 r;
    u8 *s2;
    void *temp_a1;
    u16 temp_u16;
    s32 v1;
    s32 code;
    s2 = (u8 *)D_002233A4;
    temp_u16 = D_002217E0[0];
    temp_a1 = *(void **)(s2 + 0x64);
    *(u16 *)buf = temp_u16;
    func_0011A9EC((u8 *)buf + 0x15, temp_a1);
    buf[10] = arg1;
    func_L00_005C1758((s32)(buf + 11), arg2, 0xC8);
    arg0[0xB0] = 1;
    s2[0] = 1;
    *(s32 *)(s2 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4B18((u8 *)buf, (s32)func_0015CF20, 0));
    r = 1;
    while (arg0[0xB0] != 0) {
        if (func_0015B558() != 0 || D_172160[0xB1] != 0) {
            *(s32 *)(s2 + 0x10) = 0x19;
            if (*(s32 *)(s2 + 0x14) == 0) {
                *(s32 *)(s2 + 0x14) = 0x19;
            }
            r = 0;
            break;
        }
        s2[0x1C] = 1;
        func_0015A050();
        s2[0x1C] = 0;
        if (func_L00_00774650(s2, 1) == 0) {
            r = 0;
            break;
        }
    }
    s2[0] = 0;
    arg0[0xB0] = 0;
    if (r != 0) {
        v1 = *(s32 *)(arg0 + 0xB4);
        if (v1 == -0x3DE) {
            r = 0;
        } else if (v1 == -0x3E6) {
            *(s32 *)(s2 + 0x10) = 0xF;
            if (*(s32 *)(s2 + 0x14) == 0) {
                *(s32 *)(s2 + 0x14) = 0xF;
            }
            r = 0;
        } else if (v1 == -0x3BC) {
            *(s32 *)(s2 + 0x10) = 0xF;
            if (*(s32 *)(s2 + 0x14) == 0) {
                *(s32 *)(s2 + 0x14) = 0xF;
            }
            r = 0;
        } else if (v1 != 0) {
            *(s32 *)(s2 + 0x10) = 0x19;
            if (*(s32 *)(s2 + 0x14) == 0) {
                *(s32 *)(s2 + 0x14) = 0x19;
            }
            r = 0;
        }
        if (r != 0 && arg0[0x440] != 0 && arg0[0x448] == 0) {
            r = func_L00_0076A658(arg0);
        }
    }
    return r;
}
