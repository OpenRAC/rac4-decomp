/* cflags: @ee29 -O2 -G8 */
#include "common.h"
extern void func_004FAD28(void *);
extern void func_005362F8(s32);
extern void func_L00_00535898(s32);
void func_L00_0052F6C0(void *object) {
    u8 *p = object;
    if (object != 0) {
        if (*(s32 *)(p + 0x18) != 0 && *(s32 *)(p + 0x1C) != 0)
            ((void (*)(void))*(u32 *)(p + 0x1C))();
        func_L00_00535898(*(s32 *)p);
        func_005362F8(*(s32 *)(p + 8));
        func_004FAD28(object);
    }
}
