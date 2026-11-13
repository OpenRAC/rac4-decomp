/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj_01F0C090 Obj_01F0C090;
typedef struct VT_01F0C090 {
    u8 pad0[0x80];
    s32 (*f80)(Obj_01F0C090 *, char *);
} VT_01F0C090;
struct Obj_01F0C090 {
    VT_01F0C090 *vt;
};

extern s32 D_0016E678;
extern char D_0016F5A8[];
extern char D_0019E838[];
extern char D_0019E850[];
extern char D_0019E880[];
extern char D_0019E8A0[];
extern void func_0011AFC8(char *, char *, s32);
extern void func_0011D5D8(char *, ...);
extern void func_0011D920(char *, char *, ...);
extern Obj_01F0C090 *func_01EEE1FC(void);
extern void func_01F0BF70(char *);

void func_01F0C090(char *arg0, s32 arg1) {
    char buf[256];
    Obj_01F0C090 *o;

    D_0016E678 = 1;
    func_0011AFC8(buf, arg0, 0xFF);
    func_01F0BF70(buf);
    func_0011D920(D_0016F5A8, D_0019E838, buf, arg1);
    o = func_01EEE1FC();
    if (o != NULL) {
        if (o->vt->f80(o, D_0016F5A8) != 0) {
            return;
        }
        while (1) {
        }
    }
    func_0011D5D8(D_0019E850);
    func_0011D5D8(D_0019E880, buf, arg1);
    func_0011D5D8(D_0019E8A0);
    while (1) {
    }
}
