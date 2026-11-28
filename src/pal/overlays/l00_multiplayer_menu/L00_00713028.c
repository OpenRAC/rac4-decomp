#include "pal/request_761c88.h"

extern s32 func_0011D920(s8 *dst, s8 *format, ...);
extern const char *func_0045E850(s32 id);
extern void func_L00_007144E0(void);

u8 D_L00_00220BD4 = 0;
u8 D_L00_00220BD5 = 0;
extern s32 D_003B1738[];
extern s8 D_003F40B8[];

/* Format the pending request's text when its ID matches the active entry. */
s32 func_L00_00713028(s32 status, PalRequest761C88 *request)
{
    func_L00_007144E0();
    if (status == 0 && D_L00_00220BD4 != 0 && request->word_08 == D_003B1738[0]) {
        func_0011D920(D_003F40B8, (s8 *)func_0045E850(0x3632), request->text_1b);
        D_L00_00220BD5 = 0;
        D_L00_00220BD4 = 0;
    }
    return 2;
}
