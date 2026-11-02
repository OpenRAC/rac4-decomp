#include "common.h"

extern s32 func_005062D0(s32, const char *);
typedef struct Type1 {
    char pad[0x4C];
    const char *f4C;
    char pad50[0x1B0];
} Type1;
extern Type1 D_00307354[];

/* Store the indexed label pointer and update its resource handle. */
void func_004A0ED0(s32 index, const char *text)
{
    Type1 *p = (Type1 *)((index << 9) + (u32)D_00307354);
    p->f4C = text;
    func_005062D0((index << 6) + 0x14000C, text);
}
