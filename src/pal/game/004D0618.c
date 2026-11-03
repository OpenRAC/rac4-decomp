#include "common.h"

extern s32 func_00506BB8(void);
extern void func_00502520(void *);
extern void func_004D0B60(void);
extern void func_004D07B0(void), func_004D07F0(void), func_004D08E0(void);
extern s32 func_004A2468(void *);
typedef struct Type1 {
    s32 f0, f4, f8;
    char pad[0x9D4];
} Type1;
extern Type1 D_00316D00[];

/* Process pending state changes and refresh the current slot's menu. */
void func_004D0618(void *descriptor)
{
    Type1 *p = D_00316D00 + func_00506BB8();
    switch (p->f0) {
    case 1:
        p->f0 = 0;
        break;
    case 2:
        func_00502520(descriptor);
        break;
    case 0:
        func_004D0B60();
        break;
    }
    if (p->f8 & 1)
        func_004D07B0();
    if (p->f8 & 2)
        func_004D07F0();
    func_004A2468((char *)p + 0x974);
    if (p->f8 & 4)
        func_004D08E0();
}
