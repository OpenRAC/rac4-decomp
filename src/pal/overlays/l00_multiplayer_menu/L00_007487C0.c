/* cflags:  */
#include "common.h"

// Update the handle at +0x114 from the states of the handles at +0xBC and
// +0xD0: when the first reports 3 (method at +0xA8), the second reporting 0
// clears the third (+0xA4) and runs its +0x20 method with 3, otherwise runs
// +0x20 with 0.
void func_L00_007487C0(void *object) {
    void *first;
    first = *(void **)((u8 *)object + 184);
    if ((*(s32 (**)(void *))((u8 *)*(void **)((u8 *)first + 0x58) + 0xA8))(first) == 3) {
        void *second = *(void **)((u8 *)object + 200);
        if ((*(s32 (**)(void *))((u8 *)*(void **)((u8 *)second + 0x58) + 0xA8))(second) == 0) {
            (*(void (**)(void *, s32))((u8 *)*(void **)((u8 *)*(void **)((u8 *)object + 268) + 0x58) + 0xA4))(*(void **)((u8 *)object + 268), 0);
            (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)*(void **)((u8 *)object + 268) + 0x58) + 0x20))(*(void **)((u8 *)object + 268), 3, 0);
            return;
        }
        (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)*(void **)((u8 *)object + 268) + 0x58) + 0x20))(*(void **)((u8 *)object + 268), 0, 0);
    }
}
