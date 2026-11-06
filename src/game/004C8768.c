#include "common.h"
typedef struct {
    s32 mode, flags;
    char pad[0x1304];
    char context[0x6C];
} State;
extern State D_0030D188;
extern void func_004C92C0(void), func_004C8B60(void), func_004C8C70(void), func_004C8EF8(void);
extern void func_005014B0(void *);
extern s32 func_004A1730(void *);
void func_004C8768(void *descriptor)
{
    switch (D_0030D188.mode) {
    case 0:
        D_0030D188.mode = 2;
        break;
    case 2:
        func_004C92C0();
        break;
    case 1:
        func_005014B0(descriptor);
        break;
    }
    if (D_0030D188.flags & 1)
        func_004C8B60();
    func_004A1730(D_0030D188.context);
    if (D_0030D188.flags & 2)
        func_004C8C70();
    if (D_0030D188.flags & 4)
        func_004C8EF8();
}
