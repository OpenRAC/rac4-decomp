/* cflags: -O2 -G8 */
#include "common.h"

s32 func_L00_005DD4A0(void *);
s32 func_L01_00591BD8(void *, s32, s32);
s32 func_005ADC30(s32, s32, s32);
void func_L01_0056CDB0(void *);
s32 func_L01_0056E7F8(void *);
s32 func_L01_005A8928(void *);

// Resets the object and releases the pointer held at data +0x530.
void func_L05_004DB658(void *object)
{
    void *data = *(void **)((u8 *)object + 0xAC);

    func_L01_0056CDB0(object);
    func_L01_0056E7F8(object);
    func_L01_005A8928(object);
    func_L00_005DD4A0(*(void **)((u8 *)data + 0x530));
    *(void **)((u8 *)data + 0x530) = NULL;
    func_005ADC30(0, 1024, 0);
    func_L01_00591BD8(object, 18, 2);
    func_L00_005DD4A0(object);
}
