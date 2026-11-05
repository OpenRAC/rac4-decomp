/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/record_0030F7F0.h"

/* Clear the word at 0xC of the selected record. */
void func_L00_00641BE8(s32 index) {
    D_0030F7F0[index].word_0c = 0;
}
