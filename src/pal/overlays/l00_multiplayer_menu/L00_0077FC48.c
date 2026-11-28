#include "common.h"

typedef struct {
    s32 f0;
    void (*f4)(void *, void *);
    s32 f8;
} Type1;

extern s32 D_004EF078[];
extern Type1 *D_004EF0A0[];

s32 func_L00_0077FC48(u32 category, s32 index)
{
    if (category < 9) {
        s32 count = D_004EF078[category];
        Type1 *entries = D_004EF0A0[category];

        if (index < count) {
            return entries[index].f0;
        }
    }
    return 0;
}
