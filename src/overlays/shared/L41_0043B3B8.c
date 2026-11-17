#include "common.h"

extern void func_L00_005E77D0(void *, s32, s32);
extern void func_L41_0043A960(void *);
extern void func_L41_0043B330(void *object);

// Calls the three helpers on the object at arg0 unless it is NULL or its byte at 0x20 is 0xFE or 0xFD.
void func_L41_0043B3B8(void *arg0) {
    u8 temp_v1;

    if (arg0 == 0) {
        return;
    }
    temp_v1 = *((u8 *)arg0 + 0x20);
    if (temp_v1 == 0xFE) {
        return;
    }
    if (temp_v1 == 0xFD) {
        return;
    }
    func_L00_005E77D0(arg0, 1, -1);
    func_L41_0043B330(arg0);
    func_L41_0043A960(arg0);
}
