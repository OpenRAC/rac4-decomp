/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern u16 *func_01ED0BE0(void *, u8);
extern void *func_01ED2458(void *arg0);
extern void func_01ED3B08(void *o);

typedef struct Ent {
    s32 f0;
    void *f4;
    u16 f8;
    u16 fA;
} Ent;

typedef struct Tbl {
    u32 f0;
    u8 pad4[0x10];
    u32 f14;
    u8 pad18[0x30];
    s32 f48;
    s32 f4C;
    u8 pad50[0x28];
    u8 f78;
    u8 pad79[0x13];
    u16 *f8C;
    Ent *f90;
} Tbl;

// Releases the entry matching slot idx of a session table and notifies the callback.
s32 func_01ED2538(void *s, u32 idx) {
    Tbl *t;
    u16 *p;
    Ent *e;
    u32 i;
    s32 buf[6];

    if (s == NULL) {
        return 0x17;
    }
    t = func_01ED2458(s);
    if (t == NULL) {
        return 0x17;
    }
    if (idx >= t->f0) {
        return 0x17;
    }
    p = func_01ED0BE0(s, t->f78);
    if (p == NULL) {
        return (s32)p;
    }
    i = 0;
    if (t->f14 != 0) {
        e = t->f90;
        do {
            if (t->f8C[idx] == *p) {
                *p = -2;
                e->f8 = -2;
                func_01ED3B08(e->f4);
                if (t->f48 != 0) {
                    func_0011A518(buf, 0, 0x18);
                    buf[5] = t->f4C;
                    buf[1] = idx;
                    ((void (*)(s32 *))t->f48)(buf);
                }
                return 0;
            }
            if (e->f8 == t->f8C[idx]) {
                *p = -2;
                e->f8 = -2;
                func_01ED3B08(e->f4);
                return 0;
            }
            e++;
            p++;
            i++;
        } while (i < t->f14);
    }
    return 0;
}
