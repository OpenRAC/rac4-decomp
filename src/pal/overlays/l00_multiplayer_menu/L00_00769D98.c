/* cflags: -mno-split-addresses */
#include "common.h"

extern const char *func_0045E850(s32 id);
extern const char *D_L00_00221818;
extern const char *D_L00_0022181C[];
extern const char *D_L00_00221820[];
extern const char *D_L00_00221824[];

/* Cache the four consecutive menu labels. */
void func_L00_00769D98(void)
{
    D_L00_00221818 = func_0045E850(0x3444);
    D_L00_0022181C[0] = func_0045E850(0x3445);
    D_L00_00221820[0] = func_0045E850(0x3446);
    D_L00_00221824[0] = func_0045E850(0x3447);
}
