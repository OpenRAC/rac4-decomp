/* Not matching yet: 7/21 (33.33%) relocation-masked positional words; 88/84 candidate/target bytes. One extra word; four-slot data view and index domain require review. Reproduce: python tools/check_func.py --version pal func_L00_0071BBE0 nonmatching/pal/l00_multiplayer_menu/func_L00_0071BBE0.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 D_00223340[4];
extern s32 D_00223360;
void func_L00_0071BC90(s32);
void func_L00_0071BAB0(void);
void func_L00_0071BD10(void);

void func_L00_0071BBE0(s32 index) {
    func_L00_0071BC90(index);
    func_L00_0071BAB0();
    D_00223340[index] = -1;
    D_00223360 = D_00223360 - 1;
    func_L00_0071BD10();
}
