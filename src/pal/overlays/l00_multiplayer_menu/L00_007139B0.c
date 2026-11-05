/* cflags: -O2 -G8 -Wa,-G0 */
#include "common.h"
extern int func_0045E850(int);
extern void func_L00_00713698(int);
extern void func_L00_0071DD50(void);
extern void func_L00_0071D890(float, void *, int, int, int, void (*)(void), int, int);
struct Obj { char pad[168]; unsigned char type; };
struct Context { char pad[264]; struct Obj *obj; };
extern struct Context *D_00220DD4;
extern int D_003B1738[];
int func_L00_007139B0(int a1) {
 int result = 1;
 struct Context *ctx = D_00220DD4;
 if (a1 == 2) {
  struct Obj *p = ctx->obj;
  struct Obj *q = 0;
  if (p) { if (p->type != 1) p = 0; q = p; }
  if (!q) {
   int ok = 0;
   if (D_003B1738[0] != -1) ok = result;

   if (ok) {
    int x = func_0045E850(13324);
    int y = func_0045E850(13325);
    func_L00_0071D890(0.6f,ctx,x,y,4,func_L00_0071DD50,0,0);
    func_L00_00713698(0);

   }
   result = 2;
  }
 }
 return result;
}
