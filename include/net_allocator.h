#ifndef RAC4_NET_ALLOCATOR_H
#define RAC4_NET_ALLOCATOR_H

#include "common.h"

typedef struct Rac4Allocator Rac4Allocator;
typedef struct Rac4AllocatorTable Rac4AllocatorTable;

struct Rac4Allocator {
    u8 unknown[0x10418];
    u32 f10418;
    Rac4AllocatorTable *f1041c;
};

struct Rac4AllocatorTable {
    u8 unknown[0xc];
    void *(*f0c)(Rac4Allocator *, u32, u32, s32, const char *);
    void (*f10)(Rac4Allocator *, void *);
};

/* Allocator and pointer are PS2 32-bit address words. */
s32 func_01EF0550(s32 object, s32 pointer_word);

#endif
