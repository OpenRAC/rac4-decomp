#ifndef PAL_PARSER_CONTEXT_H
#define PAL_PARSER_CONTEXT_H

#include "common.h"

typedef struct {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    s64 slen;
    u8 *max;
    u8 *q;
    u8 **pp;
    s32 line;
} PalParserContext;

#endif
