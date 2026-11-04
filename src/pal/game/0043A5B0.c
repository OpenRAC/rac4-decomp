#include "common.h"

extern void func_00163550(s32);
extern s32 func_001638B0(s32, void *, u32, s32, s32, s32, s32);
extern void func_0043A3D8(void *, u64 *, s32, s32);
extern u64 D_0021DB08;
extern char D_002481E0[];
typedef struct Type1 {
    char pad[0x64C];
    u32 f64C, f650;
    s32 f654;
} Type1;
typedef struct Type2 {
    char pad[0x14];
    s32 f14;
    char pad18[0x34];
    s32 f4C;
} Type2;
extern Type1 D_001C20C0[];
extern Type2 D_001DFD70[];

/* Transfer the image and retain the packed result of its descriptor conversion. */
void func_0043A5B0(void)
{
    u64 output[3];
    void *buffer = D_002481E0;
    func_00163550(1);
    func_001638B0(0, buffer, D_001C20C0[0].f650 + D_001C20C0[0].f64C,
                  D_001C20C0[0].f654, 0, 0, 0);
    func_0043A3D8(buffer, output, D_001DFD70[0].f4C, D_001DFD70[0].f14);
    D_0021DB08 = output[0];
}
