/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type1;

typedef struct {
    u8 pad[0x58];
    void (*handler)(Type1, Type1);
} Object;

extern void *D_00167F34;

/* Call the current object's handler with the two values. */
void func_01EA8BD0(Type1 arg0, Type1 arg1) {
    ((Object *)D_00167F34)->handler(arg0, arg1);
}
