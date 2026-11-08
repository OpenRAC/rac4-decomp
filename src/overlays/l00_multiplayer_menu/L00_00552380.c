/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x30];
    s32 f30;
    char _p34[0x9C];
    s32 fD0;
};

void func_0011A518(void *, s32, s32);
void func_L00_00553488(s32, s32, s32, s32);
void func_L00_005534B0(s32);

void func_L00_00552380(Type1 *arg0) {
    s32 temp_s1;

    temp_s1 = (void *)((u8 *)arg0 + 8);
    func_L00_005534B0(temp_s1);
    func_L00_00553488(temp_s1, 0, 0, 0);
    arg0->f30 = 0;
    arg0->fD0 = -1;
    func_0011A518((void *)((u8 *)arg0 + 0x48), 0, 0x80);
}
