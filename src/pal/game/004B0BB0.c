#include "common.h"
typedef struct {
    s32 mode;
    s32 flags;
    char rest[0x20];
} State;
extern State D_003095F8[];
extern s32 func_00506BB8(void);
extern void func_00502520(void *);
extern void func_004B0C48(void);
void func_004B0BB0(void *descriptor)
{
    State *p = &D_003095F8[func_00506BB8()];
    switch (p->mode) {
    case 0:
        break;
    case 1:
        p->mode = 0;
        break;
    case 2:
        func_00502520(descriptor);
        break;
    }
    if (p->flags & 1)
        func_004B0C48();
}
