/* cflags: -O2 -G8 */
#include "common.h"

typedef int Type1 __attribute__((mode(TI)));

s32 func_005586D0(s32 *, s32, s32, Type1 *);
s32 func_0055D3B8(s32, void *, s32);
void *func_005869E0(s32, s32);
s32 func_005A12A8(void *, s32);
s32 func_L01_004332B8(void *, s32, s32);
extern s32 D_00222B28;
extern s32 D_00222DA0;

// Allocates an object, copies its position, and initializes two data entries.
void *func_L01_004336B0(void *input, Type1 *position, Type1 *second)
{
    s32 index;
    s32 entries;
    void *data;
    void *object;

    object = func_005869E0(8216, (*(u8 *)((u8 *)input + 4) << 7) + 0x100);
    if (object != NULL) {
        data = *(void **)((u8 *)object + 0xAC);
        *(Type1 *)((u8 *)object + 0x10) = *position;
        func_005A12A8(object, 0);
        entries = (s32)data + 0x40;
        func_0055D3B8((s32)data, input, 256);
        func_L01_004332B8(object, (s32)data, 0);
        func_005586D0(&D_00222B28, entries, 0, position);
        if (second != NULL) {
            func_005586D0(&D_00222B28, entries, 1, second);
        } else {
            index = *(s32 *)((u8 *)data + 0x0C);
            if (index != -1) {
                func_005586D0(&D_00222B28, entries, 1,
                             (Type1 *)(D_00222DA0 + (index << 7) + 0x30));
            }
        }
    }
    return object;
}
