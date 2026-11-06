#ifndef PAL_REQUEST_761C88_H
#define PAL_REQUEST_761C88_H
#include "common.h"
typedef struct PalRequest761C88 {
    s32 word_00, word_04, word_08;
    char text_0c[15];
    char text_1b[384];
    struct PalRequest761C88 *next_19c;
} PalRequest761C88;
typedef char PalRequestSizeCheck[(sizeof(PalRequest761C88) == 416) ? 1 : -1];
#endif
