#include "common.h"

typedef struct {
    u8 pad[0x300];
    u8 f300;
    u8 pad301[3];
} Type1;

extern void *func_0054A998(s32 arg0);
extern s32 func_0054AB78(s32 arg0);
extern s32 func_0054ACE8(void *arg0);
extern Type1 D_1F87F0[];

// Return 0 for a zero arg or a gated entry; else whether func_0054ACE8 accepts the object at its 0x38.
s32 func_0054AC58(s32 arg0) {
    void *temp_v0;
    s32 rem;
    s32 flags;

    if (arg0 == 0) {
        return 0;
    }
    temp_v0 = func_0054A998(arg0);
    if (*(s32 *)((u8 *)temp_v0 + 0x48) == -1) {
        rem = (func_0054AB78(*(s32 *)temp_v0) - 1) % 20;
        flags = ((Type1 *)(rem * 0x304 + (u8 *)D_1F87F0))->f300;
        if (!((flags >> 3) & 1)) {
            return 0;
        }
    }
    return func_0054ACE8((u8 *)temp_v0 + 0x38) != 0;
}
