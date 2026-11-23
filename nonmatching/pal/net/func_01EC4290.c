/* Not matching yet: PAL WIP; main net.text 0x01EC4290, 132B. Not part of the build. */
/*
 * New compiled124B versus complete native132B. No duplicate among all41 actual retained objects,
 * including all7 Studio116B drafts.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d1cb73aed20440a4bdf5c95b39cff0d8c4e0e0e8d7812b8fd0e5da4ca97375bf
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EC4290 nonmatching/pal/net/func_01EC4290.c --diff
 */
#include "common.h"

extern s32 func_01EA7E28(s32 handle, s32 *output);
extern s32 func_01EC3498(void);
extern s32 func_01EC5280(s32 index);
extern s32 func_01EC3460(void);

/* Enter, resolve the indexed object and return its nested handle output. */
s32 func_01EC4290(s32 index, s32 *output)
{
    s32 entered;
    s32 address;
    s32 status;
    s32 result;
    u8 *nested;

    entered = func_01EC3460();
    result = entered;
    if (entered == 0) {
        address = func_01EC5280(index);
        status = 2;
        if ((address != 0) && (output != NULL)) {
            nested = *(u8 **)((u8 *)address + 0x9C);
            if (nested != NULL) {
                status = func_01EA7E28(*(s32 *)(nested + 0x1C), output);
            } else {
                status = 2;
            }
        }
        func_01EC3498();
        result = status;
    }
    return result;
}
