/* cflags: -O2 -G8 -Wuninitialized -Wa,-G0 -ffunction-sections */
#include "common.h"
extern int func_0045E850(int);
extern void func_L00_00713698(int);
#include "pal/dialog_71d890.h"
struct Obj { char pad[168]; unsigned char type; };
struct Context { char pad[264]; struct Obj *obj; };
struct Context *D_00220DD4 = 0;
extern int D_003B1738[];
int func_L00_00713A78(int a1) {
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
    int x = func_0045E850(13326);
    int y = func_0045E850(13327);
    func_L00_0071D890(0.6f,ctx,x,y,4,func_L00_0071DD50,0,0);
    func_L00_00713698(0);

   }
   result = 2;
  }
 }
 return result;
}

extern s32 func_0011D920(s8 *, s8 *, ...);
#include "pal/request_761c88.h"
extern int func_L00_0070D8B0(PalRequest761C88 *);
extern int D_00223510;
extern int D_00220B00;
extern int D_00220B54;
extern int D_00220B58;
#include "pal/profile_001721E0.h"
extern char D_004BFB70[];
extern char D_00221720[];
/* Formats an online request and waits for completion or cancellation. */
int func_L00_00761C88(void *arg0, int arg1) {
    PalRequest761C88 request;
    int value, finished, result;
    void *context;
    int first;
    request.word_08 = arg1;
    request.word_00 = D_00223510;
    request.word_04 = 1;
    value = -1;
    if (*((unsigned char *)arg0 + 0x298)) value = D_00220B00;
    context = D_00220DD4;
    if (D_001721E0.region20.bytes[0x1BC]) {
        func_0011D920((s8 *)request.text_1b,(s8 *)D_004BFB70,D_00220B54,D_00220B58,value,D_001721E0.region20.bytes+0x1BC);
    } else {
        func_0011D920((s8 *)request.text_1b,(s8 *)D_00221720,D_00220B54,D_00220B58,value);
    }
    result = 1;
    do {
        finished = func_L00_0070D8B0(&request);
        if (finished) break;
        first = func_0045E850(11990);
        if (func_L00_0071D890(0.6f,context,first,func_0045E850(13371),24,func_L00_0071DD50,0,0)==16) {
            result=0;
            finished=1;
        }
    } while (!finished);
    return result;
}
