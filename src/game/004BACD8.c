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
