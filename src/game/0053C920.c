#include "common.h"
typedef struct { unsigned a:4; unsigned b:6; unsigned c:4; unsigned rest:18; int pad; int f8; char pad2[68]; int f50; char f54; char f55; } Type1;
extern Type1 *func_0053CA80(void);
extern void func_0053CB70(Type1 *, int, int);
extern int D_00172170[];
Type1 *func_0053C920(int *arg0, int arg1, int arg2, int arg3) {
 Type1 *p = func_0053CA80();
 p->a = arg1;
 p->f8 = *arg0;
 p->b = 0;
 p->c = D_00172170[0];
 p->f54 = 0;
 p->f50 = -1;
 p->f55 = 1;
 func_0053CB70(p, arg2, arg3);
 return p;
}
