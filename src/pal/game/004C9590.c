#include "common.h"
typedef struct {
    s32 mode, flags;
    char pad[0x1304];
    char context[0x6C];
} State;
extern State D_0030D188;
extern void func_004CA0E8(void), func_004C9988(void), func_004C9A98(void), func_004C9D20(void);
extern void func_00502520(void *);
extern s32 func_004A2468(void *);
void func_004C9590(void *descriptor)
{
    switch (D_0030D188.mode) {
    case 0:
        D_0030D188.mode = 2;
        break;
    case 2:
        func_004CA0E8();
        break;
    case 1:
        func_00502520(descriptor);
        break;
    }
    if (D_0030D188.flags & 1)
        func_004C9988();
    func_004A2468(D_0030D188.context);
    if (D_0030D188.flags & 2)
        func_004C9A98();
    if (D_0030D188.flags & 4)
        func_004C9D20();
}
