/* cflags: -O2 -G8 */
#include "common.h"

typedef int Type1 __attribute__((mode(TI)));

s32 func_00452EC0(s32 *, s32, s32, Type1 *);
s32 func_00453F30(s32, void *, s32);
void *func_0046C1F0(s32, s32);
s32 func_0047C2F0(void *, s32);
s32 func_L01_004340D0(void *, s32, s32);
extern s32 D_00222C28;
extern s32 D_00222EA0;

// Allocates an object, copies its position, and initializes two data entries.
void *func_L01_004344E8(void *input, Type1 *position, Type1 *second)
{
    s32 index;
    s32 entries;
    void *data;
    void *object;

    object = func_0046C1F0(8216, (*(u8 *)((u8 *)input + 4) << 7) + 0x100);
    if (object != NULL) {
        data = *(void **)((u8 *)object + 0xAC);
        *(Type1 *)((u8 *)object + 0x10) = *position;
        func_0047C2F0(object, 0);
        entries = (s32)data + 0x40;
        func_00453F30((s32)data, input, 256);
        func_L01_004340D0(object, (s32)data, 0);
        func_00452EC0(&D_00222C28, entries, 0, position);
        if (second != NULL) {
            func_00452EC0(&D_00222C28, entries, 1, second);
        } else {
            index = *(s32 *)((u8 *)data + 0x0C);
            if (index != -1) {
                func_00452EC0(&D_00222C28, entries, 1,
                             (Type1 *)(D_00222EA0 + (index << 7) + 0x30));
            }
        }
    }
    return object;
}
