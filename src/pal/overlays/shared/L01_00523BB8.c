/* cflags: -Os -G8 */
#include "common.h"

s32 func_0043AED0(s32);
void *func_00511CC0(s32);
s32 func_L00_00591E00(s32);
s32 func_L00_005A1078(void);
s32 func_L01_00523680(void *);
s32 func_L01_0053B7F8(s32, void *, f32);
extern s32 D_0021E8A4;
extern s32 D_0021E8A8;

void func_L01_00523BB8(void *object) {
    void *state;

    state = *(u8 **)((u8 *)object + 0x70) + 0xE0;
    if (D_0021E8A4 == 0 && D_0021E8A8 == 1 && func_L00_005A1078() != 0) {
        func_0043AED0(*(s32 *)((u8 *)object + 0x94));
        return;
    }
    if (D_0021E8A4 != 1) {
        func_L00_00591E00(*(s32 *)((u8 *)object + 0x94));
        *(s32 *)((u8 *)func_00511CC0(*(s32 *)((u8 *)object + 0x94)) + 0x3F4) = 2;
    }
    func_L01_00523680(object);
    if (*(s32 *)((u8 *)state + 0x40) != 0) {
        *(s8 *)((u8 *)object + 0x89) = 0;
        func_L01_0053B7F8(*(s32 *)((u8 *)object + 0x94), (u8 *)object + 0x30, 0.5f);
    }
}
