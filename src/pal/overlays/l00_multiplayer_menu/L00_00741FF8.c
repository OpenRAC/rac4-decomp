/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/request_761c88.h"
extern s32 func_0011D920(s8 *, s8 *, ...);
extern int func_L00_0070D8B0(PalRequest761C88 *);
extern int D_00223504;
extern char D_004BD288[];
/* Submit a formatted request. */
int func_L00_00741FF8(int a1)
{
    PalRequest761C88 request;
    request.word_00 = D_00223504;
    request.word_04 = 1;
    func_0011D920((s8 *)request.text_1b, (s8 *)D_004BD288);
    request.word_08 = a1;
    return func_L00_0070D8B0(&request);
}
