#include "common.h"

extern void func_00502520(void *);
extern void func_004B2048(void);
extern void func_004B20C8(void);
typedef struct Type1 {
    char pad[8];
    s32 f8;
    char padC[0x2C];
    u8 f38;
} Type1;
extern Type1 D_00309750[];

/* Process descriptor state and any deferred refresh. */
void func_004B1FC8(void *descriptor)
{
    switch (D_00309750[0].f8) {
    case 0:
        break;
    case 1:
        D_00309750[0].f8 = 0;
        break;
    case 2:
        func_00502520(descriptor);
        break;
    }
    func_004B2048();
    if (D_00309750[0].f38)
        func_004B20C8();
}
