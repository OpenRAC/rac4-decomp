/* Store the result of the observed overlay helper in the 32-bit global. */
/* cflags: -G0 */
#include "common.h"

extern s32 D_00173A1C;
s32 func_L00_006FEDE8();

void func_L00_006FEEE8(void) {
    D_00173A1C = func_L00_006FEDE8();
}
