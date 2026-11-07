/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_01EAA7B8(s32, s32, void *);
extern s32 func_01EDA3C0;

s32 func_01ED93E8(void) {
    return (func_01EAA7B8(0x22, 4, &func_01EDA3C0) == 0) ? 0 : -1;
}
