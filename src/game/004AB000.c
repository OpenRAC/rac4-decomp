#include "common.h"

typedef struct {
    u8 pad00[0x158];
    s32 f158;
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    u8 pad16C[4];
} Record;

extern Record D_00308B80[];
extern void func_00496B28(void *record, s32 mode);

/* Fill the five parameter words of one record and hand it to the mode-3 pass. */
void func_004AB000(s32 index, s32 a, s32 b, s32 c, s32 d, s32 e)
{
    D_00308B80[index].f158 = a;
    D_00308B80[index].f15C = b;
    D_00308B80[index].f160 = c;
    D_00308B80[index].f164 = d;
    D_00308B80[index].f168 = e;
    func_00496B28(&D_00308B80[index], 3);
}
