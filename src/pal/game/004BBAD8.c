#include "common.h"
extern void func_004985F0(int);
extern void func_004BBB50(int);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
extern int D_002218E0;
extern int D_003D9624[];
unsigned char D_0021F97A = 0;
extern unsigned char D_0021F978;
extern int D_0021DEF4;
extern char D_0030A4E0[];
/* Select the panel mode and refresh its displayed text. */
void func_004BBAD8(int a)
{
    s32 p;
    if (!a) {
        func_004985F0(4);
        func_004BBB50(0);
    } else
        func_004985F0(11);
    D_0021F97A = 0;
    D_0021F978 = 0;
    p = func_004A2798(&D_002218E0, D_003D9624[0]);
    func_005062D0(p, D_0030A4E0 + D_0021DEF4 * 48);
}

extern s32 func_00499120(s32 mode);
extern s32 func_00506BB8(void);
extern void func_0049BF40(s32 context);
extern void func_004BB638(s32 direction);
extern void func_004BB5B8(s32 direction);
extern void func_004BB740(void);

void func_004BB6A0(void)
{
    if (!D_0021F97A) {
        s32 direction = 0;
        switch (func_00499120(6)) {
        case 2:
            func_0049BF40(func_00506BB8());
            break;
        case 7:
            direction = 1;
        case 1:
        case 8:
            func_004BB638(direction);
            break;
        case 5:
            direction = 1;
        case 6:
            func_004BB5B8(direction);
            break;
        case 13:
            func_004BB740();
            break;
        }
    }
}
