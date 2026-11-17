/* Not matching yet: 10/11 (90.91%) relocation-masked positional instructions; 44/44 bytes; addu operand order differs. Reproduce: python tools/check_func.py --version pal func_L01_00570278 nonmatching/pal/l01_dreadzone_station/func_L01_00570278.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
s32 func_L01_00570278(s32 *arg0, s32 arg1) {
 if (arg1 < 0 || arg1 >= arg0[16]) return 0;
 return arg0[arg1];
}
