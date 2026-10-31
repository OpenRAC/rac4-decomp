#include "common.h"

extern s32 func_00157F98(void);
extern void func_00158898(s32 arg0);
extern s32 func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0047F550(s32 arg0);
extern void func_00489478(void);
extern void func_0048F7E0(u8 *arg0);

/* Runs a setup step when func_0047F550(3) is zero, then calls the function pointer at offset 4 of the object from func_0046D428 */
void func_00459978(void) {
    s32 *temp_v0;
    void (*temp_v0_2)(void);

    if (func_0047F550(3) == 0) {
        func_00158898(1);
        func_00489478();
        func_00157F98();
    }
    func_0048F7E0(0);
    temp_v0 = (s32 *)func_0046D428(0x2120, 0, 0xC);
    if (temp_v0 != NULL) {
        temp_v0_2 = (void (*)(void))temp_v0[1];
        if (temp_v0_2 != NULL) {
            temp_v0_2();
        }
    }
}
