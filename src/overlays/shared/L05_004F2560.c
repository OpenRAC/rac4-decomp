#include "common.h"

extern void func_L00_0066CCE8(void *, s32);
extern s32 func_L01_0056CDB0(u8 *object);
extern void func_L01_0056E7F8(void *arg0);
extern s32 func_L01_00588B08(void *object);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8928(u8 *obj);

/* Run the four setup calls on arg0, then set or clear flags on the object at arg0+0xAC+0x450 and call 00591BD8. */
void func_L05_004F2560(u8 *arg0) {
    u8 *s1 = *(u8 **)(arg0 + 0xAC);
    u8 *p;
    u8 *q;

    func_L01_0056CDB0(arg0);
    func_L01_0056E7F8(arg0);
    func_L01_005A8928(arg0);
    func_L01_00588B08(arg0);
    p = *(u8 **)(s1 + 0x450);
    if (p != 0) {
        *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 0x41;
        q = *(u8 **)(s1 + 0x450);
        *(u16 *)(q + 0x34) = *(u16 *)(q + 0x34) & 0xEFFF;
        *(s32 *)(*(u8 **)(s1 + 0x450) + 0x98) = 0;
        func_L00_0066CCE8(*(u8 **)(s1 + 0x450), 1);
    }
    func_L01_00591BD8(arg0, 7, 5);
}
