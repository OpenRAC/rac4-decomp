#include "common.h"
typedef struct {
    s32 mode;
    s32 flags;
    char rest[0x20];
} State;
extern State D_003094F8[];
extern s32 func_00505B20(void);
extern void func_005014B0(void *);
extern void func_004AFDB8(void);
void func_004AFD20(void *descriptor)
{
    State *p = &D_003094F8[func_00505B20()];
    switch (p->mode) {
    case 0:
        break;
    case 1:
        p->mode = 0;
        break;
    case 2:
        func_005014B0(descriptor);
        break;
    }
    if (p->flags & 1)
        func_004AFDB8();
}
