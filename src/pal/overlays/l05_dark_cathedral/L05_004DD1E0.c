/* cflags: -O2 -G8 */
#include "common.h"

s32 func_0046C6B0(void *);
s32 func_00474368(void *, s32, s32);
s32 func_L00_00625420(s32, s32, s32);
void func_L01_0056F988(void *);
s32 func_L01_005713D8(void *);
s32 func_L01_005ACCA0(void *);

// Resets the object and releases the pointer held at data +0x530.
void func_L05_004DD1E0(void *object)
{
    void *data = *(void **)((u8 *)object + 0xAC);

    func_L01_0056F988(object);
    func_L01_005713D8(object);
    func_L01_005ACCA0(object);
    func_0046C6B0(*(void **)((u8 *)data + 0x530));
    *(void **)((u8 *)data + 0x530) = NULL;
    func_L00_00625420(0, 1024, 0);
    func_00474368(object, 18, 2);
    func_0046C6B0(object);
}
