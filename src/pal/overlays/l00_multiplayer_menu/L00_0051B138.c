/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef struct WordArray {
    s32 count;
    s32 *values;
} WordArray;

s32 func_L00_0051B138(WordArray **array, s32 index);

s32 func_L00_0051B138(WordArray **array, s32 index)
{
    WordArray *words = *array;

    if (words == NULL)
        goto missing;
    if (index >= words->count)
        goto missing;
    goto found;
missing:
    return 0;
found:
    return words->values[index];
}
