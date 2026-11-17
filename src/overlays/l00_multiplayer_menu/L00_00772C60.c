#include "common.h"

extern s32 func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7A58(u8 *obj, s32 arg1, s32 arg2);
extern void func_0015D2B8(void);
extern u16 D_00221848[];
extern u8 *D_002233A4;

// Copies the global list into the object at arg0, then reports the result of func_0015B558 through the global state.
s32 func_L00_00772C60(u8 *arg0) {
    u8 sp[0x30];
    u8 *g;
    u8 *lst;
    u8 *l2;
    u8 *obj;
    void *name;
    s32 ret;
    s32 i;
    s32 v;
    s32 t;

    g = D_002233A4;
    name = *(void **)(g + 0x64);
    *(u16 *)&sp[0] = D_00221848[0];
    func_0011A9EC(&sp[0x15], name);
    arg0[0] = 1;
    t = func_0012FEB0(func_0012E370(), 0x24000);
    arg0[0xD] = 0;
    *(s32 *)(arg0 + 4) = t;
    lst = arg0 + 0x14;
    i = 0;
    if (*(s32 *)(lst + 4) > 0) {
        do {
            l2 = arg0 + 0x14;
            obj = *(u8 **)(arg0 + 0x20);
            v = ((s32 *)*(u8 **)(l2 + 8))[i];
            i += 1;
            *(s32 *)((u8 *)v + *(s32 *)(obj + 0xC)) = *(s32 *)(obj + 0x1C);
            *(s32 *)(obj + 0x1C) = v;
            *(s32 *)(obj + 0x18) += 1;
        } while (i < *(s32 *)(l2 + 4));
    }
    *(s32 *)(arg0 + 0x18) = 0;
    ret = 1;
    func_0015B548(func_01ED7A58(sp, (s32)func_0015D2B8, 0));
    if (func_0015B558() != 0) {
        *(s32 *)(g + 0x10) = 0x44;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = 0x44;
        }
        ret = 0;
    }
    return ret;
}
