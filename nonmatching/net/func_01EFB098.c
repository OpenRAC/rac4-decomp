/* Not matching yet: BYTES 22/144 (tools/try_func.py func_01EFB098 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */

extern void func_01EFA118(void *, s8, s32);
extern void func_01EFAA2C(void *, void *);

typedef struct {
    u8 pad0[0x80];
    void *f80;
    s32 pad84[0x14];
    s32 fD4;
    s32 padD8[3];
    s32 fE4;
    s32 padE8[2];
    s32 fF0;
    s32 fF4;
    s32 padF8[8];
    s32 f118;
} Obj;

typedef struct { s16 h[6]; } Entry;

void func_01EFB098(Obj *o) {
    s32 idx = o->fF4;
    Entry *t = (Entry *)o->f118;
    s32 val = o->fE4;
    o->fD4 = val;
    if (val < t[idx].h[0]) {
        if (idx > 0) {
            if (idx == o->fF0) {
                func_01EFA118(o, -0x7F, 1);
                return;
            } else {
                o->fF4 = idx - 1;
                func_01EFAA2C(o, *(void **)o->f80);
                return;
            }
        }
    } else {
        func_01EFAA2C(o, *(void **)o->f80);
    }
}
