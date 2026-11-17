/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_00517808(void);
extern s32 func_L00_004FAAC0();
extern void func_L00_004F89B0(void *arg0);
extern s32 func_L00_004F8B28(void *arg0, void *arg1);
extern s64 func_L00_004FABB0(void);
extern void func_L00_00519DC8(s32 arg0);
extern s32 D_004AD240[];

/* Passes a key to the child at the object's 0x8, releasing the child when its 0x30 field is zero. */
void func_L00_0051A080(s64 arg0)
{
    u8 *obj;
    s32 temp_s0;
    s64 buf[50];

    obj = func_00517808();
    if (*(void **)(obj + 8) != 0) {
        if (arg0 == 0) {
            arg0 = func_L00_004FABB0();
        }
        buf[0] = arg0;
        func_L00_004FAAC0(9, 1, D_004AD240, 0x27C);
        temp_s0 = func_L00_004F8B28(*(void **)(obj + 8), buf);
        if (*(s64 *)((u8 *)*(void **)(obj + 8) + 0x30) == 0) {
            func_L00_004F89B0(*(void **)(obj + 8));
            *(void **)(obj + 8) = 0;
        }
        func_L00_004FAAC0(0xA, 1, D_004AD240, 0x28E);
        if (temp_s0 != 0) {
            func_L00_00519DC8(temp_s0);
        }
    }
}
