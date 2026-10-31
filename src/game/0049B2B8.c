#include "common.h"

extern void *func_00510BE8(void);
extern u8 D_0021EE18;

/* Check a flag; if set, return 0; if clear, call function and check a field's bit. */
s32 func_0049B2B8(void) {
    void *temp;
    void *ptr;
    u8 byte;

    if (D_0021EE18 != 0) {
        return 0;
    }

    temp = func_00510BE8();
    ptr = *(void **)((char *)temp + 0x2F00);
    byte = *(u8 *)((char *)ptr + 0x551);
    byte ^= 1;
    return byte != 0;
}
