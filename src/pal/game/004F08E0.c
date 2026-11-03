#include "common.h"

typedef struct Type1 {
    s32 f0, f4;
    char pad[0x28];
    s32 f30;
    char *f34;
    s32 f38, f3C, f40;
} Type1;

/* Return one or two contiguous ranges from the buffered data. */
void func_004F08E0(Type1 *p, void **first, s32 *firstSize, void **second, s32 *secondSize)
{
    if (!p->f0) {
        if (p->f4 != 4) {
            *first = (char *)p + (p->f30 + 8);
            *firstSize = 0x28 - p->f30;
            *second = p->f34;
            *secondSize = p->f40;
        } else {
            *first = p->f34;
            *firstSize = p->f40;
            *second = 0;
            *secondSize = 0;
        }
    } else {
        s32 size = p->f40 - p->f3C;
        s32 offset = p->f38;
        if (p->f40 - offset >= size) {
            *first = p->f34 + offset;
            *firstSize = size;
            *second = 0;
            *secondSize = 0;
        } else {
            *first = p->f34 + offset;
            *firstSize = p->f40 - p->f38;
            *second = p->f34;
            *secondSize = size - (p->f40 - p->f38);
        }
    }
}
