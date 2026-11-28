#include "pal/object_callback.h"
#include "pal/object_data.h"

extern s32 func_00453CE8(void *);
extern void func_L15_004DE138(u8 *);
extern s32 func_L15_004E4E18(u8 *);
extern s32 func_L15_004E4F90(u8 *);
extern s32 func_L15_004E5100(u8 *);
extern f32 func_L01_00598DF8(s32 *, s32, s32);
extern void func_L15_004DDDB8(void *object);
extern void func_L15_004D9DE8(u8 *);
extern void func_L15_004DAB20(u8 *);
extern PalObjectCallbackNode *D_L15_00222518;

s32 D_L15_002221DC = 0;

/* Step the object's timers, record three query results, and nudge the shared counter when active. */
void func_L15_004D9D28(u8 *obj) {
    u8 *state;

    state = (u8 *)((PalObject *)obj)->data;
    func_00453CE8(state + 0x1D0);
    func_L15_004DE138(obj);
    *(s32 *)(state + 0x394) = func_L15_004E4E18(obj);
    *(s32 *)(state + 0x3A4) = func_L15_004E4F90(obj);
    *(s32 *)(state + 0x3F0) = func_L15_004E5100(obj);
    if (obj[0x20] != 0)
        func_L01_00598DF8(&D_L15_002221DC, 0x2BF20, 1);
    if (*(f32 *)(state + 0x260) > 0.0f) {
        PalObjectCallback cb = func_L15_004DDDB8;
        func_00449A28(&D_L15_00222518, cb, obj);
    }
    func_L15_004D9DE8(obj);
    func_L15_004DAB20(obj);
}
