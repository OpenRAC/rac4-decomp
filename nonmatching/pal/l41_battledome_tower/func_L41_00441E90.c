/* Not matching yet: 34/38 (89.47%) relocation-masked positional words; 152/152 candidate/target bytes. Global ownership and return type remain unproved. Reproduce: python tools/check_func.py --version pal func_L41_00441E90 nonmatching/pal/l41_battledome_tower/func_L41_00441E90.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern u8 D_0036D600[];
float func_L41_00441CE0(int);

void func_L41_00441E90(int a1, int a2)
{
    int v3 = *(int *)(a2 + 172);
    int v5 = *(int *)(a1 + 12052);
    if (*(u8 *)(a1 + 9837)) {
        float v6;
        float v8;
        int v7;
        int v4 = *(int *)(a1 + 12048);

        *(int *)(v3 + 48) = v4;
        v6 = func_L41_00441CE0(v5);
        v7 = *(int *)(v3 + 4);
        v8 = 1.0f;
        if (v7 != 10 && D_0036D600[v7 + 1438] == 3)
            v8 = 0.5f;
        *(float *)(v3 + 40) += (v6 * 0.0099999998f) * v8;
    }
}
