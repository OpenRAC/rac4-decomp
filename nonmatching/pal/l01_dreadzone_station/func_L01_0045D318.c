/* Not matching yet: 7/11 (63.64%) relocation-masked positional instructions; 44/44 bytes; branch scheduling differs. Reproduce: python tools/check_func.py --version pal func_L01_0045D318 nonmatching/pal/l01_dreadzone_station/func_L01_0045D318.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
int func_L01_0045D318(int a) { int v=*(int *)(a+172); int r; if (*(unsigned char *)(v+1560)==1) r=*(int *)(v+1536)!=-1; else r=0; return r; }
