/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Obj Obj;
typedef struct { Obj *obj; s32 f4; s32 f8; s32 fC; s32 f10; } Msg;
struct Obj {
    char _p0[0x430];
    void (*f430)(Msg *);
    s32 f434;
    char _p438[0x1C];
    s32 f454;
    char _p458[0x10];
    s32 f468;
};
extern void *func_0011A518(void *, s32, s32);
void func_01EA50C0(s32 code, Obj *o) {
    Msg m;
    if (o == 0) {
        return;
    }
    if (o->f468 != 2) {
        return;
    }
    if (o->f430 == 0) {
        return;
    }
    func_0011A518(&m, 0, 0x14);
    m.obj = o;
    o->f454 = 4;
    m.f4 = 4;
    m.f8 = 1;
    if (code == 0xD4E9) {
        m.fC = 0xE;
    } else {
        m.fC = 0x25;
    }
    m.f10 = o->f434;
    o->f430(&m);
}
