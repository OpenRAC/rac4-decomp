#include "common.h"

/* Return the 0x14 word of the first lookup's result minus the 0x10 word of the second's, plus one. */
extern void *func_0054A980(s32 arg0);

s32 func_0054AA58(s32 arg0) {
    void *temp_s1;
    void *temp_v0;

    temp_s1 = func_0054A980(arg0);
    temp_v0 = func_0054A980(arg0);
    return (*(s32 *)((u8 *)temp_s1 + 0x14) - *(s32 *)((u8 *)temp_v0 + 0x10)) + 1;
}
