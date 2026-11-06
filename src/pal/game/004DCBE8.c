#include "common.h"
typedef struct {
    s32 mode, flags;
    char rest[0x160];
} State;
extern State D_00322FC8[];
extern s32 func_00506BB8(void);
extern void func_004DCCB8(void), func_004DD160(void), func_004DD558(void), func_004DDA40(void), func_004DD810(void), func_00502520(void *);
void func_004DCBE8(void *descriptor)
{
    State *p = D_00322FC8 + func_00506BB8();
    switch (p->mode) {
    case 0:
        p->mode = 2;
        break;
    case 2:
        func_004DCCB8();
        break;
    case 1:
        func_00502520(descriptor);
        break;
    }
    if (p->flags & 1)
        func_004DD160();
    if (p->flags & 2)
        func_004DD558();
    func_004DDA40();
    func_004DD810();
}
