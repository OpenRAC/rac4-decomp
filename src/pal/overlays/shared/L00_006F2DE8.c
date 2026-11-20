#include "common.h"
#include "pal/profile_001721E0.h"

extern u8 *D_00343E78[];
extern void func_L00_006FCC10(void *);
extern void func_L00_006D5A78(u8 *);
extern void func_L00_006ACF68(s32);
extern void func_L00_005DFE40(s32);
extern void func_L00_006F45A8(u8 *, s32);
extern void func_L00_006F9A40(s32, s32);

static inline u8 *profile(void) {
    return (u8 *)&D_001721E0;
}

// slot release
void func_L00_006F2DE8(s32 *owner) {
    u8 **slot;
    u8 *obj;
    u8 *state;
    s32 i;

    state = profile() + 0x7F9;
    slot = D_00343E78;
    for (i = 0; i < 10; i++, state++, slot++) {
        obj = *slot;
        if (obj == NULL || *(s32 **)(obj + 0x2F28) == NULL || *(s32 **)(obj + 0x2F28) != owner || obj[0x266D] != 0) {
            continue;
        }
        if (*state != 2) {
            *state = 2;
            func_L00_006FCC10(owner + 6);
        }
        func_L00_006D5A78(obj);
        func_L00_006ACF68(*(s32 *)(obj + 0x2EF0));
        func_L00_005DFE40(*(s32 *)(obj + 0x2EF0));
        *(s32 *)(obj + 0x2EF0) = 0;
        *(s32 *)(obj + 0x2F28) = 0;
        *slot = NULL;
        func_L00_006F45A8(obj, *owner);
        func_L00_006F9A40(i, *owner);
        return;
    }
}
