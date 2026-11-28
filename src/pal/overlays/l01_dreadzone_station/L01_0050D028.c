#include "common.h"
#include "pal/object_data.h"

typedef struct {
    u8 pad[0x798];
    s32 f798;
} StationObjectData;

extern s32 func_00489438(u8 *obj, f32 x, f32 y, f32 z);
extern s32 func_L01_0050CFD0(u8 *obj);
extern void func_L01_0050D128(u8 *obj, s32 state, s32 mode, s32 arg3);

void func_L01_0050D028(u8 *obj) {
    StationObjectData *data;
    s32 state;
    f32 step;

    data = (StationObjectData *)((PalObject *)obj)->data;
    step = 0.011170108f;
    func_00489438(obj, step, step, 0.50265485f);
    state = data->f798;
    if (state > 0) {
        func_L01_0050D128(obj, state, -1, 0);
        return;
    }
    func_L01_0050D128(obj, func_L01_0050CFD0(obj), -1, 0);
}
