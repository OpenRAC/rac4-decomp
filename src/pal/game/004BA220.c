/* cflags: -Wuninitialized */
#include "common.h"

typedef struct {
    s32 mode;
    s32 selection;
    s32 displayMode;
    s32 resource;
} MenuContext;

extern s32 D_002218B8;
extern s32 D_002218B0;
extern s32 func_00506BB8(void);
extern void func_0049E0D0(s32 slot, s32 item, s32 group);
extern void func_004BA898(void);
extern void func_0049AA18(s32 resource);
extern void func_0049BE10(s32 slot);
extern void func_00502520(void *object);
extern void func_004BA450(void);

static inline MenuContext *menu_context(s32 slot)
{
    return (MenuContext *)((u32)&D_002218B8 + ((u32)slot << 4));
}

void func_004BA220(void)
{
    s32 slot = func_00506BB8();
    MenuContext *context = menu_context(slot);

    func_0049E0D0(slot, 0, D_002218B0);
    func_004BA898();
    if (context->resource != 0) {
        func_0049AA18(context->resource);
        context->resource = 0;
    }
    func_0049BE10(slot);
}

void func_004BA2A0(void *object)
{
    MenuContext *context = menu_context(func_00506BB8());

    switch (context->mode) {
    case 1:
        context->mode = 0;
        break;
    case 2:
        func_00502520(object);
        break;
    case 0:
        func_004BA450();
        break;
    }
}
