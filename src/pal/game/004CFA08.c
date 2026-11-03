#include "common.h"

extern s32 func_00506BB8(void);
extern void func_00502520(void *);
extern void func_004CFE50(void);
extern void func_004CFC10(void), func_004CFC50(void), func_004CFD10(void);
extern s32 func_004A2468(void *);
typedef struct Type1 {
    s32 f0, f4, f8;
    char pad[0x1030];
} Type1;
extern Type1 D_0030F820[];
/* Process pending state changes and refresh the current slot's menu. */
void func_004CFA08(void *descriptor)
{
    Type1 *p = D_0030F820 + func_00506BB8();
    switch (p->f0) {
    case 1:
        p->f0 = 0;
        break;
    case 2:
        func_00502520(descriptor);
        break;
    case 0:
        func_004CFE50();
        break;
    }
    if (p->f8 & 1)
        func_004CFC10();
    if (p->f8 & 2)
        func_004CFC50();
    func_004A2468((char *)p + 0xF90);
    if (p->f8 & 4)
        func_004CFD10();
}
