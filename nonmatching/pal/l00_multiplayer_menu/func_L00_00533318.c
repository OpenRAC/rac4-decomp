/* Not matching yet: 12/14 (85.71%) relocation-masked positional words; 56/56 candidate/target bytes. Branch-likely scheduling differs; data owner remains unproved. Reproduce: python tools/check_func.py --version pal func_L00_00533318 nonmatching/pal/l00_multiplayer_menu/func_L00_00533318.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef struct Type1 Type1;
struct Type1 { char f00[0x28]; void *f28; Type1 *f2c; };
extern char D_004A2FA8[];
s32 func_L00_00533318(Type1 *arg0) { s32 result = 0, value; Type1 *p; if (arg0 != NULL) { p = arg0->f2c; if (p != arg0 || (value = 0, p->f28 != D_004A2FA8)) value = 0x212; result = value; } return result; }
