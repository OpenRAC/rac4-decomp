#include "common.h"
typedef struct {
    s32 a, b, c;
} Data;
extern char D_00239640[];
extern s32 D_002213F8;
extern void func_0044B3D0(void);
extern void func_0044D860(void *);
extern void func_0044D4B0(s32, u64, u64, u64, s32, s32);
void func_0044DFE0(Data *p, s32 a, s32 b, s32 c)
{
    if (!*(u8 *)D_00239640)
        func_0044B3D0();
    else if (D_002213F8 != 8) {
        func_0044B3D0();
        func_0044D860(D_00239640);
    }
    func_0044D4B0(a, p->a, p->b, p->c, b, c);
}
