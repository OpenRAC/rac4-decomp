/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef union {
    struct {
        unsigned int f0 : 8;
        unsigned int f8 : 8;
        unsigned int f10 : 8;
        unsigned int f18 : 8;
    } fields;
    u32 word;
} Type1;

extern s32 func_L00_0050C230(u8 *output);
extern void func_L00_0050CF60(u32 seed);

/* Seed the generator from four bytes of the output record. */
s32 func_L00_0050CFE0(void)
{
    u8 output[8];
    Type1 seed;

    func_L00_0050C230(output);
    seed.fields.f0 = output[5];
    seed.fields.f8 = output[3];
    seed.fields.f10 = output[2];
    seed.fields.f18 = output[1];
    func_L00_0050CF60(seed.word);
    return 0;
}
