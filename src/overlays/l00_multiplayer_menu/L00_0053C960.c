/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_00516F10(void);
s32 func_L00_0053C960(u8 *arg0) {
    u8 *object = func_L00_004FACD8(0x14);
    s32 value;
    if (object == 0) return 0;
    value = func_L00_00516F10();
    *(s32 *)object = value;
    if (value == 0) {
        func_004FAD28(object);
        return 0;
    }
    *(s32 *)(object + 4) = 0;
    *(s32 *)(object + 8) = 0;
    *(s32 *)(object + 0xC) = 0;
    *(s32 *)(object + 0x10) = 0;
    *(s32 *)(arg0 + 0xC) = (s32)object;
    return 1;
}
