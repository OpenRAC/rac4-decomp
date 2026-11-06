#include "common.h"
typedef struct Type1 {
    char p[0x24];
    int f24;
    char q[0x14];
    short f3C;
    char r[2];
    unsigned char f40, f41, f42, f43;
    int f44;
    char s[6];
    short f4E;
    char t[0x1C];
    int f6C;
    char u[6];
    short f76;
    char v[0x44];
    int fBC;
    char w[6];
    short fC6;
} Type1;
extern Type1 D_00206948[];
extern int D_002214D0;
extern unsigned int D_0021F354;
extern void func_00489F30(void *);
/* Reset the shared panel fields and initialize its entries. */
void func_00488EB8(void)
{
    Type1 *p = D_00206948;
    p->f3C = p->f24 = -1;
    p->f40 = 32;
    p->f42 = 0;
    p->f43 = 0;
    p->f44 = 0;
    p->f4E = 0;
    p->f6C = 0;
    p->f76 = 0;
    p->fBC = 0;
    p->fC6 = 0;
    p->f41 = 0;
    func_00489F30(&D_002214D0);
    D_0021F354 = 0xFFFFFFFFu;
}
