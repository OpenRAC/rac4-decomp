#include "common.h"

extern void func_L00_0066D220(s32, s32, void *);

typedef struct { u8 pad[0x20]; u8 state; } Obj;

void func_L01_00518500(Obj *arg0) {
    if (arg0->state == 0) {
        arg0->state++;
        func_L00_0066D220(0, 4, arg0);
    }
}
