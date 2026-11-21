/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void func_L00_004F89B0(void *arg0);
extern void func_L00_004F8C38(void *a1, void *a2);
extern void func_L00_00508338(void *);
extern void func_L00_0051C468(void);
extern s32 D_00476F7C[];
extern s64 *D_004A03AC[];
extern void *D_004A03B4[];
extern void *D_004A03B8[];
extern void *D_004A03BC[];

/* Restores or tears down the menu entry after running its handler. */
void func_L00_0051C498(s32 arg0) {
    s64 *p;
    s64 saved;

    p = D_004A03AC[0];
    if (p != 0) {
        saved = p[5];
        D_00476F7C[0] = arg0;
        p[5] = 0;
        func_L00_004F8C38(p, (void *)func_L00_0051C468);
        if (arg0 < 0) {
            func_L00_004F89B0(D_004A03AC[0]);
            func_L00_00508338(D_004A03B8[0]);
            func_L00_00508338(D_004A03B4[0]);
            func_L00_00508338(D_004A03BC[0]);
            D_004A03AC[0] = 0;
            D_004A03B8[0] = 0;
            D_004A03B4[0] = 0;
            D_004A03BC[0] = 0;
        } else {
            D_004A03AC[0][5] = saved;
        }
    }
}
