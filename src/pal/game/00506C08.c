#include "common.h"

typedef struct Type1 {
    s32 f0;
    char *f4;
} Type1;
extern Type1 D_00222138[];
extern Type1 *func_00502150(void);
extern s32 func_00500CF0(void *, s32, s32);

/* Add a resource handle to the active object's indexed slot. */
s32 func_00506C08(s32 index, s32 handle)
{
    Type1 *p;
    char *state;
    void *selected;
    s32 result = 0;
    if (D_00222138[0].f4)
        p = D_00222138;
    else
        p = func_00502150();
    state = p->f4;
    selected = 0;
    if (state)
        selected = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    if (selected)
        result = func_00500CF0(selected, index, handle);
    return result;
}
