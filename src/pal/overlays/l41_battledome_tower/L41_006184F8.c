/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/profile_001721E0.h"
void func_L00_007031C0(u8 *, s32);
void func_L00_007031F0(u8 *, s32);
void *func_L00_007043E8(void *);
void func_L00_00706160(s32);
void func_L41_006184F8(void *arg0) {
    u8 *p;
    void *entry;
    u8 result;
    u8 index, kind;
    func_L00_00706160((s32)*(void **)((u8 *)arg0 + 0x26e4));
    p = *(void **)((u8 *)arg0 + 0x26e4);
    entry = *(void **)((u8 *)p + 0x2c);
    index = *(u8 *)((u8 *)arg0 + 0x2f10);
    if (entry != 0) {

        if ((s32)D_001721E0.region20.words.f218 >= *(s32 *)((u8 *)entry + 4) && index == *(u8 *)((u8 *)entry + 1)) {
            kind = *(u8 *)((u8 *)entry + 3);
            switch (kind) {
            case 1: func_L00_007031C0(p, index); result = 1; break;
            case 2: func_L00_007031F0(p, index); result = 1; break;
            default: result = (s32)((u32)*(s32 *)((u8 *)entry + 4) + 0x4b0U) < (s32)D_001721E0.region20.words.f218; break;
            }
            if (result) func_L00_007043E8(*(void **)((u8 *)arg0 + 0x26e4));
        }
    }
}
