#include "common.h"
typedef struct {
    const void *a, *b, *c;
} Data;
extern char D_00239540[];
extern s32 D_002212F8;
extern void func_0044AD28(void);
extern void func_0044D1B8(void *);
extern void func_0044CE08(s32, const void *, const void *, const void *, s32, s32);
void func_0044D938(Data *p, s32 a, s32 b, s32 c)
{
    if (!*(u8 *)D_00239540)
        func_0044AD28();
    else if (D_002212F8 != 8) {
        func_0044AD28();
        func_0044D1B8(D_00239540);
    }
    func_0044CE08(a, p->a, p->b, p->c, b, c);
}
