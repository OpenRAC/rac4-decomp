#ifndef RECORD_0030F7F0_H
#define RECORD_0030F7F0_H
#include "common.h"

/* The indexed records are 0x1F8 bytes. Only these two aligned words are interpreted. */
typedef struct {
    u8 bytes_00[0xC];
    u32 word_0c;
    u32 word_10;
    u8 bytes_14[0x1E4];
} Record0030F7F0;

typedef char Record0030F7F0SizeCheck[(sizeof(Record0030F7F0) == 0x1F8) ? 1 : -1];
typedef char Record0030F7F0AlignmentCheck[(__alignof__(Record0030F7F0) == 4) ? 1 : -1];
extern Record0030F7F0 D_0030F7F0[];
#endif
