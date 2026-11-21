/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

extern void *func_01EA90F0();
extern s32 func_01EA95C0();
extern void func_01EB2F70(void *owner);
extern void func_01EB3060(void *l, void *n);
extern s32 *D_0016819C[];

// Unlinks the node from the global list, frees its pending entries and releases it through func_01EA95C0.
void func_01EB3CE0(void) {
    s32 *nd;
    s32 *lst;
    s32 *lst2;
    s32 s0;
    s32 sp0;

    nd = (s32 *)func_01EA90F0();
    if (nd == 0) {
        return;
    }
    s0 = nd[3];
    if (s0 != 0) {
        do {
            func_01EB3060(nd, (void *)s0);
            func_01EB2F70((void *)s0);
            s0 = nd[3];
        } while (s0 != 0);
    }
    if (nd[8] != 0) {
        func_01EA95C0(&nd[8]);
    }
    if (nd[7] != 0) {
        sp0 = nd[7];
        func_01EA95C0(&sp0);
        nd[7] = 0;
    }
    if (nd[11] != 0) {
        func_01EA95C0(&nd[11]);
    }
    if (nd[9] != 0) {
        func_01EA95C0(&nd[9]);
    }
    if (nd[10] != 0) {
        func_01EA95C0(&nd[10]);
    }
    lst = D_0016819C[0];
    if (lst[0] == (s32)nd) {
        lst[0] = nd[1];
    }
    ((s32 *)nd[1])[0] = nd[0];
    ((s32 *)nd[0])[1] = nd[1];
    lst2 = D_0016819C[0];
    if (lst2[0] == (s32)nd) {
        lst2[0] = 0;
    }
    sp0 = (s32)nd;
    func_01EA95C0(&sp0);
}
