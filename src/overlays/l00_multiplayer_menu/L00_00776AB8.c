#include "common.h"

extern u16 D_00221878[];
extern s32 D_002233A4;
extern u8 D_172160[];
extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7048(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00774650(u8 *obj, s32 arg1);
extern void func_0015D308();

/* Starts a request on the global slot with a copied name, waits until it is free, then returns the reply area when it succeeds, else NULL. */
void *func_L00_00776AB8(u8 *arg0, s32 arg1) {
    u8 obj[0x50];
    u8 *g;
    u8 *tbl;
    void *name;
    s32 s3;
    s32 one;
    s32 flag;
    s32 v1;
    void *res;

    one = 1;
    g = (u8 *)D_002233A4;
    name = *(void **)(g + 0x64);
    *(u16 *)obj = D_00221878[0];
    func_0011A9EC(obj + 0x15, name);
    *(s32 *)(obj + 0x28) = one;
    func_L00_005C1758((s32)(obj + 0x30), arg1, 0x20);
    arg0[0x14C] = one;
    g[0] = one;
    s3 = 1;
    flag = 1;
    *(s32 *)(g + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED7048(obj, (s32)func_0015D308, 0));
    tbl = D_172160;
    while (arg0[0x14C] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tbl + 0x2C4) != 0) {
            *(s32 *)(g + 0x10) = 0x48;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x48;
            }
            s3 = 0;
            break;
        }
        g[0x1C] = flag;
        func_0015A050();
        g[0x1C] = 0;
        if (func_L00_00774650(g, 1) == 0) {
            s3 = 0;
            break;
        }
    }
    g[0] = 0;
    res = 0;
    arg0[0x14C] = 0;
    if (s3 != 0) {
        v1 = *(s32 *)(arg0 + 0x168);
        if (v1 == -0x3DD) {
            *(s32 *)(g + 0x10) = 0x47;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x47;
            }
            s3 = 0;
        } else if (v1 != 0) {
            *(s32 *)(g + 0x10) = 0x48;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x48;
            }
            s3 = 0;
        }
        res = (s3 == 0) ? 0 : (void *)(arg0 + 0x150);
    }
    return res;
}
