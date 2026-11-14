#include "common.h"

extern void func_00488BD0();
extern void func_L00_005DD4A0(void *);
extern void func_L00_0066CCE8(void *, s32);
extern s32 func_L01_0056CDB0(u8 *object);
extern void func_L01_0056E7F8(void *arg0);
extern s32 func_L01_00588B08(void *object);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8928(u8 *obj);
extern void func_L05_00491D18();

/* tears down an object's child list and switches state */
void func_L05_004910E0(u8 *arg0, s32 arg1) {
    u8 *state = *(u8 **)(arg0 + 0xAC);
    u8 *n;
    u8 *next;
    func_L05_00491D18(arg0);
    func_L00_0066CCE8(arg0, 0);
    n = *(u8 **)(state + 0x244);
    if (n != 0) {
        do {
            next = *(u8 **)(*(u8 **)(n + 0xAC) + 0x2A4);
            func_00488BD0(n);
            n = next;
        } while (n != 0);
    }
    *(s32 *)(state + 0x244) = 0;
    func_L01_0056CDB0(arg0);
    func_L01_0056E7F8(arg0);
    func_L01_005A8928(arg0);
    func_L01_00588B08(arg0);
    func_L01_00591BD8(arg0, 7, 2);
    if (*(u8 *)(state + 0x1A8) == 0) {
        func_L01_00588B08(arg0);
    } else if (arg1 == 0) {
        func_L00_005DD4A0(arg0);
    }
}
