/* cflags: -O2 -G8 */
#include "common.h"
typedef struct {
    char pad[0x18];
    short f18;
    char pad2[0x196];
    int f1b0;
    char pad3[0x10];
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
} Data;
extern char D_001719C8[];
#define DATA (*(Data *)D_001719C8)
extern int *D_0021DDF8;
extern int D_0021EE3C, D_002213E0;
int D_0021F710 = 0, D_0021F714 = 0;
extern int func_00469A80(int *, int);
extern int func_00469B10(int *);
extern int func_00469D70(int *, int, void *);
extern const char *func_0045E898(s32);
extern void func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_004A3378(s32);
/* Advances the object-state sequence and opens its completion message. */
void func_004A3180(void)
{
    int *p;
    int x;
    int temp;

    if (D_0021F710 < 4 && !D_0021DDF8)
        D_0021F710 = 4;
    D_0021F714++;
    p = D_0021DDF8;
    switch (D_0021F710) {
    case 0:
        if (D_0021F714 >= 21)
            D_0021F710 = 1;
        break;
    case 1:
        if (DATA.f1c4 < 3 && DATA.f1cc < 0) {
            DATA.f1b0 = 0;
            if (DATA.f18 < -1 || !func_00469A80(p, 0x10000))
                goto reset;
            D_0021F710 = 2;
        }
        break;
    case 2:
        x = func_00469B10(p);
        if (x >= 0) {
            if (DATA.f1d4) {
                *p = 0;
                DATA.f1d4 = 0;
                D_0021F710 = 4;
            } else if (x > 0) {
                if (!func_00469D70(p, 0x10000, &temp)) {
                    func_0049F4C8(0, func_0045E898(14196), func_004A3378,
                                  2, 0, 0, 0, -1.0f);
                } else {
                    *p = 0;
                    func_0049F4C8(0, func_0045E898(14217), func_004A3378,
                                  2, 0, 0, 0, -1.0f);
                }
                D_0021F710 = 3;
            } else {
            reset:
                *p = 0;
                D_0021F710 = 4;
            }
        }
        break;
    case 3:
        D_0021F714 = 0;
        break;
    case 4:
        if (D_0021F714 >= 21) {
            D_002213E0 = 0;
            D_0021EE3C = 1;
        }
        break;
    case 5:
        break;
    }
}
