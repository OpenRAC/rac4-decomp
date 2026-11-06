#include "common.h"
extern void func_00497980(int);
extern void func_004BAD50(int);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505238(s32, const char *);
extern int D_002217E0;
extern int D_003D95AC[];
unsigned char D_0021F8DA = 0;
extern unsigned char D_0021F8D8;
extern int D_0021DE6C;
extern char D_0030A4E0[];
/* Select the panel mode and refresh its displayed text. */
void func_004BACD8(int a)
{
    s32 p;
    if (!a) {
        func_00497980(4);
        func_004BAD50(0);
    } else
        func_00497980(11);
    D_0021F8DA = 0;
    D_0021F8D8 = 0;
    p = func_004A1A60(&D_002217E0, D_003D95AC[0]);
    func_00505238(p, D_0030A4E0 + D_0021DE6C * 48);
}

extern void func_004985F0(int);
extern void func_004BBB50(int);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
extern int D_002218E0;
extern int D_003D9624[];
extern unsigned char D_0021F978;
extern int D_0021DEF4;
extern char D_0030A4E0[];

extern s32 func_004983E8(s32 mode);
extern s32 func_00505B20(void);
extern void func_0049B208(s32 context);
extern void func_004BA820(s32 direction);
extern void func_004BA7A0(s32 direction);
extern void func_004BA928(void);

void func_004BA888(void)
{
    if (!D_0021F8DA) {
        s32 direction = 0;
        switch (func_004983E8(6)) {
        case 2:
            func_0049B208(func_00505B20());
            break;
        case 7:
            direction = 1;
        case 1:
        case 8:
            func_004BA820(direction);
            break;
        case 5:
            direction = 1;
        case 6:
            func_004BA7A0(direction);
            break;
        case 13:
            func_004BA928();
            break;
        }
    }
}
