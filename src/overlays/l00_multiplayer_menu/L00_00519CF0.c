#include "common.h"

/* Clear the two words at 0x74 and 0x78 of the given object. */
void func_L00_00519CF0(void *arg0) {
    (*(s32 *)((u8 *)arg0 + 0x78)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x74)) = 0;
}
