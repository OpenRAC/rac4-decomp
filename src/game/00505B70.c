#include "common.h"

typedef struct Type1 {
    s32 f0;
    char *f4;
} Type1;
extern Type1 D_00222038[];
extern Type1 *func_005010E0(void);
extern s32 func_004FFC80(void *, s32, s32);

/* Add a resource handle to the active object's indexed slot. */
s32 func_00505B70(s32 index, s32 handle)
{
    Type1 *p;
    char *state;
    void *selected;
    s32 result = 0;
    if (D_00222038[0].f4)
        p = D_00222038;
    else
        p = func_005010E0();
    state = p->f4;
    selected = 0;
    if (state)
        selected = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    if (selected)
        result = func_004FFC80(selected, index, handle);
    return result;
}
