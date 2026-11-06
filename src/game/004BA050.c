#include "common.h"

typedef struct Type1 {
    int f0, f4, f8;
} Type1;
extern Type1 D_00171D38[];
extern int D_002217E0;
extern char D_0030A540[];
extern int D_003D9534[];
extern void func_001586A8(int);
extern void func_00497980(int);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505238(s32, const char *);
/* Toggle the selected mode and refresh its label. */
void func_004BA050(int a)
{
    if (a) {
        int b = D_00171D38[0].f8 == 0;
        D_00171D38[0].f8 = b;
        func_001586A8(b ^ 1);
        func_00497980(16);
    }
    func_00505238(func_004A1A60(&D_002217E0, D_003D9534[0]), D_0030A540 + D_00171D38[0].f8 * 48);
}
