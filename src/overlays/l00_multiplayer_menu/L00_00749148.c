#include "common.h"

extern void func_007497C0(void *);
extern void func_L00_0069D028(s32, s32);
extern s32 func_L00_0071B3C8();
extern void func_L00_0071BAF8();
extern void func_L00_0071BB90(void *, s32, u32);
extern void func_L00_00749458(void *, s32);
extern s32 func_L00_007647B0(s32 identifier);

/* Resets the menu state and plays a sound if flagged. */
void func_L00_00749148(u8 *arg0) {
    void *obj;
    func_L00_0071BAF8();
    func_L00_0071BB90(arg0, 0x16, 0xFFFFFFFF);
    func_007497C0(arg0);
    func_L00_0069D028(*(s32 *)(arg0 + 0x240) | 0x23, 0);
    func_L00_0069D028(*(s32 *)(arg0 + 0x240) | 0x21, 0);
    func_L00_0069D028(*(s32 *)(arg0 + 0x240) | 0x19, 0);
    func_L00_0069D028(*(s32 *)(arg0 + 0x240) | 0x18, 0);
    func_L00_0071B3C8(arg0);
    obj = *(void **)(arg0 + 0xCC);
    (*(void (**)(void *, s32, s32))(*(u8 **)((u8 *)obj + 0x58) + 0x20))(obj, 2, 0);
    *(u8 *)(arg0 + 0x66C) = 0;
    *(s32 *)(arg0 + 0x670) = -1;
    func_L00_00749458(arg0, *(s32 *)(arg0 + 0x668));
    if (*(u8 *)(arg0 + 0x674) != 0) {
        func_L00_007647B0(0xBA);
    }
}
