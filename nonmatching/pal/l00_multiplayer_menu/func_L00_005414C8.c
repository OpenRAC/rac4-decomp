/* Not matching yet: 8/14 (57.14%) relocation-masked positional words; 36/56 candidate/target bytes. One call delay slot differs and five words after return are omitted. Reproduce: python tools/check_func.py --version pal func_L00_005414C8 nonmatching/pal/l00_multiplayer_menu/func_L00_005414C8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 func_L00_0051CF88(void *);
extern void func_L00_00541498(void);

/* Process the input, then invoke the shared follow-up. */
void func_L00_005414C8(void *input)
{
    func_L00_0051CF88(input);
    func_L00_00541498();
}
