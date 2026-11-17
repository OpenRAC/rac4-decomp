/* Not matching yet: 12/23 (52.17%) relocation-masked positional words; 92/92 candidate/target bytes. Callee signatures and stack-buffer contract remain hypotheses. Reproduce: python tools/check_func.py --version pal func_L00_004EF400 nonmatching/pal/l00_multiplayer_menu/func_L00_004EF400.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
void *func_0011A518(void *, int, unsigned int);
int func_00126BA0(void *);
int func_L00_004EF400(int a1,int a2,int a3) {
 u32 values[6];
 func_0011A518(values,0,24);
 values[2] = a1;
 values[1] = a2;
 values[5] = a3;
 return func_00126BA0(values);
}
