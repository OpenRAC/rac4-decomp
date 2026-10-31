/* cflags: -O2 -G8 */
#include "common.h"
typedef struct { char pad[0x18]; short f18; char pad2[0x196]; int f1b0; char pad3[0x10]; int f1c4; int f1c8; int f1cc; int f1d0; int f1d4; } Data;
extern char D_001719C8[];
#define DATA (*(Data *)D_001719C8)
extern int *D_0021DDF8;
extern int D_0021EE2C, D_00221360;
int D_0021F6D0 = 0, D_0021F6D4 = 0;
extern int func_FB_00469328(int *, int);
extern int func_FB_004693B8(int *);
extern int func_FB_00469618(int *, int, void *);
extern int func_FB_0045E140(int);
extern void func_FB_0049ED88(int, int, void *, int, int, int, int, float);
extern void func_FB_004A2C38(void);
void func_FB_004A2A40(void) {
 int *p; int x; int temp;
 if (D_0021F6D0 < 4 && !D_0021DDF8) D_0021F6D0 = 4;
 D_0021F6D4++;
 p = D_0021DDF8;
 switch (D_0021F6D0) {
 case 0: if (D_0021F6D4 >= 21) D_0021F6D0 = 1; break;
 case 1:
   if (DATA.f1c4 < 3 && DATA.f1cc < 0) {
    DATA.f1b0 = 0;
    if (DATA.f18 < -1 || !func_FB_00469328(p, 0x10000)) goto reset;
    D_0021F6D0 = 2;
   } break;
 case 2:
   x = func_FB_004693B8(p);
   if (x >= 0) {
    if (DATA.f1d4) { *p = 0; DATA.f1d4 = 0; D_0021F6D0 = 3; }
    else if (x > 0) {
     if (!func_FB_00469618(p, 0x10000, &temp)) {
      func_FB_0049ED88(0, func_FB_0045E140(14196), func_FB_004A2C38, 2, 0, 0, 0, -1.0f);
     } else {
      *p = 0; func_FB_0049ED88(0, func_FB_0045E140(14217), func_FB_004A2C38, 2, 0, 0, 0, -1.0f);
     }
     D_0021F6D0 = 3;
    } else { reset: *p = 0; D_0021F6D0 = 4; }
   } break;
 case 3: D_0021F6D4 = 0; break;
 case 4: if (D_0021F6D4 >= 21) { D_00221360 = 0; D_0021EE2C = 1; } break;
 case 5: break;
 }
}
