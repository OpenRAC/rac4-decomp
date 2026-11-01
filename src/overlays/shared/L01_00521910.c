/* cflags: -Os -G8 */
#include "common.h"

s32 func_00535988(s32);
void *func_006658C0(s32);
s32 func_L00_00591410(s32);
s32 func_L00_005A00F8(void);
s32 func_L01_005213D8(void *);
s32 func_L01_00538F40(s32, void *, f32);
extern s32 D_0021E824;
extern s32 D_0021E828;

void func_L01_00521910(void *object) {
    void *state;

    state = *(u8 **)((u8 *)object + 0x70) + 0xE0;
    if (D_0021E824 == 0 && D_0021E828 == 1 && func_L00_005A00F8() != 0) {
        func_00535988(*(s32 *)((u8 *)object + 0x94));
        return;
    }
    if (D_0021E824 != 1) {
        func_L00_00591410(*(s32 *)((u8 *)object + 0x94));
        *(s32 *)((u8 *)func_006658C0(*(s32 *)((u8 *)object + 0x94)) + 0x3F4) = 2;
    }
    func_L01_005213D8(object);
    if (*(s32 *)((u8 *)state + 0x40) != 0) {
        *(s8 *)((u8 *)object + 0x89) = 0;
        func_L01_00538F40(*(s32 *)((u8 *)object + 0x94), (u8 *)object + 0x30, 0.5f);
    }
}
