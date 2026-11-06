#include "common.h"

typedef struct Type1 {
    s32 f0, f4, f8;
} Type1;
extern Type1 D_0030E9D8[];
extern s32 func_004CAF90(s32);
extern void func_004CAA50(s32), func_004CAEC8(s32), func_0049C248(s32, s32), func_0049C328(s32, s32, s32), func_0049C200(s32, s32);
void func_004CA948(void)
{
    if (D_0030E9D8[0].f8 & 1) {
        s32 i;
        if (D_0030E9D8[0].f4 != -1) {
            if (!func_004CAF90(D_0030E9D8[0].f4))
                D_0030E9D8[0].f4 = -1;
        }
        i = 0;
        do {
            func_004CAA50(i);
            if (D_0030E9D8[0].f4 == -1 && func_004CAF90(i))
                D_0030E9D8[0].f4 = i;
            i++;
        } while (i < 4);
        if (D_0030E9D8[0].f4 == -1)
            func_0049C248(0, 0);
        else {
            func_0049C328(0, 0, 1);
            func_0049C200(0, 0);
        }
        func_004CAEC8(D_0030E9D8[0].f4);
        D_0030E9D8[0].f8 &= ~1;
    }
}
