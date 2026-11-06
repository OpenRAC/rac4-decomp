/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/record_0030F7F0.h"

/* Clear the word at 0x10 of the selected record. */
void func_L00_00641C08(s32 index) {
    D_0030F7F0[index].word_10 = 0;
}
