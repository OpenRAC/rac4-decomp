/* Not matching yet: EXACT by bytes (SIZE 72/72, try_func) but the two -1 stores are emitted in ascending address order (0x221100 then 0x221104) where retail stores 0x221104 first; tools/audit_relocs.py reports the GPREL16 pair swapped. The only source form that fixes the order (a shared base pointer) costs 4 bytes, and -fno-schedule-insns2 changes the bytes. Store-order wall. (tools/try_func.py func_L00_0073D9E8 --diff). Not part of the build. */
/* cflags: -O2 -G8 */
#include "common.h"

extern s32 func_0011D9A8(void *p, const char *fmt, ...);
extern s8 D_00221170[];

s32 D_00221100 = 0;
s32 D_00221104 = 0;
s8 D_00221109 = 0;

s32 func_L00_0073D9E8(s32 unused0, u8 *arg1) {
    (void)unused0;

    if (func_0011D9A8(arg1 + 0x1B, D_00221170, &D_00221100, &D_00221104) != 2) {
        D_00221104 = -1;
        D_00221100 = -1;
    }
    D_00221109 = 0;
    return 2;
}
