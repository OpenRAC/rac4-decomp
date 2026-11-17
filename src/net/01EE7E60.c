/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_001BD2B0[5];
extern s32 func_01EEE39C(void);
extern s32 func_01EEE1FC(void);
extern s32 func_01EEE13C(void);
extern s32 func_01EEE45C(void);
extern s32 func_01EEE2DC(void);
extern s32 func_01EEE3FC(void);
extern s32 func_01EEE27C(void);
extern s32 func_01EEE19C(void);
extern s32 func_01EEE4BC(void);
extern s32 func_01EEE33C(void);
typedef struct { char _p0[0x3A2C]; s32 f3A2C; } Obj;
void func_01EE7E60(Obj *o) {
    if (o->f3A2C) {
        D_001BD2B0[3] = func_01EEE39C();
        D_001BD2B0[0] = func_01EEE1FC();
        D_001BD2B0[2] = func_01EEE13C();
        D_001BD2B0[4] = func_01EEE45C();
        D_001BD2B0[1] = func_01EEE2DC();
    } else {
        D_001BD2B0[3] = func_01EEE3FC();
        D_001BD2B0[0] = func_01EEE27C();
        D_001BD2B0[2] = func_01EEE19C();
        D_001BD2B0[4] = func_01EEE4BC();
        D_001BD2B0[1] = func_01EEE33C();
    }
}
