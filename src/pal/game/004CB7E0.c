#include "common.h"

typedef struct Type1 {
    s32 f0, f4, f8;
} Type1;
extern Type1 D_0030E9D8[];
extern s32 func_004CBE30(s32);
extern void func_004CB8E8(s32), func_004CBD68(s32), func_0049CF80(s32, s32), func_0049D060(s32, s32, s32), func_0049CF38(s32, s32);
void func_004CB7E0(void)
{
    if (D_0030E9D8[0].f8 & 1) {
        s32 i;
        if (D_0030E9D8[0].f4 != -1) {
            if (!func_004CBE30(D_0030E9D8[0].f4))
                D_0030E9D8[0].f4 = -1;
        }
        i = 0;
        do {
            func_004CB8E8(i);
            if (D_0030E9D8[0].f4 == -1 && func_004CBE30(i))
                D_0030E9D8[0].f4 = i;
            i++;
        } while (i < 4);
        if (D_0030E9D8[0].f4 == -1)
            func_0049CF80(0, 0);
        else {
            func_0049D060(0, 0, 1);
            func_0049CF38(0, 0);
        }
        func_004CBD68(D_0030E9D8[0].f4);
        D_0030E9D8[0].f8 &= ~1;
    }
}
