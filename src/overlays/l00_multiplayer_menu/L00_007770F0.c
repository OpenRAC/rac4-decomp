#include "common.h"
typedef struct {
 int f0; char f4; char pad5[0xBB]; char fC0; char padC1[0x23];
 char fE4; char padE5[7]; char fEC; char padED[7]; char fF4;
 char padF5[0x67]; char f15C, f15D; char pad15E[2]; int f160, f164;
 char f168; char pad169[3]; int f16C, f170; char pad174[0x24];
 char f198, f199; char pad19A[2]; int f19C, f1A0; char f1A4;
 char pad1A5[3]; int f1A8, f1AC;
} Type1;
/* Initialize the object fields. */
Type1 *func_L00_007770F0(Type1 *p) {
 p->f0 = -1;
 p->f4 = 0; p->fC0 = 0; p->fE4 = 0; p->fEC = 0; p->fF4 = 0;
 p->f15C = 0; p->f15D = 0; p->f160 = -1; p->f164 = -1;
 p->f168 = 0; p->f16C = 10000; p->f170 = -1;
 p->f198 = 0; p->f199 = 0; p->f19C = -1; p->f1A0 = -1; p->f1A4 = 0; p->f1AC = -1; p->f1A8 = 10000;
 return p;
}
