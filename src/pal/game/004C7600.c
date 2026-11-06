#include "common.h"

extern s32 func_004C7690(void);
extern s32 func_00506BB8(void);
typedef struct Type1 {
    char pad[0x30];
    s32 f30;
} Type1;
typedef struct Type2 {
    char pad[0xB2C];
    s32 fB2C;
} Type2;
extern Type1 D_0030D038[];
extern Type2 D_0030B9D8[];
extern char D_001F8878[];

/* Query the current history entry's enabled flag. */
s32 func_004C7600(void)
{
    Type1 *p = (Type1 *)((u32)D_0030D038 + func_004C7690() * 0x34);
    s32 index = func_00506BB8();
    s32 offset = p->f30 * 12;
    Type2 *history = D_0030B9D8 + index;
    offset += ((history->fB2C - 1) % 20) * 0x304;
    return (u8)D_001F8878[offset + 9] != 0;
}
