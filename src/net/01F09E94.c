/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-gcse -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 {
    void *f0;
    void *f4;
} Type1;

void *func_0011A518(void *, s32, s32);
void func_01F0C090(s32 *, s32);
extern s32 D_0019E5C0[];

void func_01F09E94(Type1 *arg0)
{
    if (arg0->f0 == NULL || arg0->f4 == NULL) {
        func_01F0C090(D_0019E5C0, 0x58);
    }
    func_0011A518(arg0->f0, 0, 0x20);
    func_0011A518(arg0->f4, 0, 0x101);
}
