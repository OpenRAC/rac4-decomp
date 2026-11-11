/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_1BCC28[];
/* Syscall ABI reference: ps2dev/ps2sdk (Academic Free License 2.0),
 * ee/kernel/include/kernel.h and syscallnr.h. Implementation reconstructed
 * from RAC4 retail; see THIRD_PARTY_NOTICES.md. */
extern s32 func_00126BD0(s32);
/* Dispatch the stored value when its guard is clear. */
void func_00154240(void)
{
    if (!D_1BCC28[14]) func_00126BD0(D_1BCC28[10]);
}
