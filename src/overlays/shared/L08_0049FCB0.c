#include "common.h"

extern u8 *D_00222694;
extern void func_L00_005DD4A0(void *);

// Clears the back-links of a linked object's children, recurses into the first, then releases it.
void func_L08_0049FCB0(void *arg0) {
    s32 none = -1;
    s32 *links = *(s32 **)((u8 *)arg0 + 0xAC);
    s32 *p = links + 1;
    s32 i = 1;
    s32 idx;
    s32 next;

    do {
        idx = *p;
        if (idx != none) {
            **(s32 **)(D_00222694 + (idx << 8) + 0xAC) = none;
        }
        i--;
        p++;
    } while (i >= 0);
    next = links[0];
    if (next != -1) {
        func_L08_0049FCB0(D_00222694 + (next << 8));
    }
    func_L00_005DD4A0(arg0);
}
