#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

extern void func_L00_0070F320(void);
extern void func_L00_00713EA0(void);

/* Clear the profile selectors and copy the menu word at +0x60 into +0x128. */
void func_L00_0071C350(void) {
    Type4 *profile = &D_001721E0;
    s32 *src = *(s32 **)((u8 *)D_002234A4 + 0x60);
    s32 missing = -1;
    s32 value;

    profile->region20.words.f34 = missing;
    profile->region20.words.fFE = 0;
    profile->region20.words.f11C = missing;
    profile->region20.words.fD8 = missing;
    profile->region20.words.f120 = 0;
    profile->region20.words.fFD = 0;
    profile->region20.words.fDC = 0;
    value = *src;
    profile->f2D5 = 0;
    profile->region20.words.f128 = value;
    func_L00_0070F320();
    func_L00_00713EA0();
}
