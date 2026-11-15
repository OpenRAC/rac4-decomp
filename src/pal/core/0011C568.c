/* cflags: -fno-opt-stack */
/* Matching reconstruction; public algorithm reference: newlib/libc/stdio/findfp.c
 * newlib 8a0efa53e44919bcf5ccb1d3353618a82afdf8bc.
 * Original notice retained below; this is not an unchanged vendor file. */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "common.h"

typedef struct FILE_ {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *bfbase;
    s32 bfsize;
    s32 lbfsize;
    u8 pad1c[0x14];
    u8 *ubbase;
    s32 ubsize;
    u8 pad38[0xC];
    u8 *lbbase;
    s32 lbsize;
    u8 pad4c[8];
    u8 *data;
} FILE_;

typedef struct Glue {
    struct Glue *next;
    s32 niobs;
    FILE_ *iobs;
} Glue;

typedef struct {
    s32 err;
    u8 pad4[0x34];
    s32 didinit;
    u8 pad3c[0x19C];
    Glue glue;
} Reent;

extern void *func_00124F98(Reent *, u32);
extern void *func_0011A518(void *, s32, s32);

Glue *func_0011C568(Reent *d, s32 n) {
    s32 size;
    Glue *g;
    FILE_ *data;

    size = n * 0x58;
    g = func_00124F98(d, size + 0xC);
    if (g == 0) {
        return 0;
    }
    data = (FILE_ *)((u8 *)g + 0xC);
    g->niobs = n;
    g->next = 0;
    g->iobs = data;
    func_0011A518(data, 0, size);
    return g;
}
