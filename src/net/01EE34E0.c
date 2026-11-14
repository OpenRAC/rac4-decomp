/* cflags: @ee296 -Os -G0 */
#include "common.h"

typedef struct { s32 *f0; s32 f4; s32 f8; } Hdr;
extern void *func_01EE3D48(s32);
extern Hdr *func_01EE3DB0(void *, s32);
extern void func_01EE32FC(void);
extern void func_01EE347C(void);
extern void func_01EE34A8(void);
extern void *func_01EE40B8(void *, Hdr *, void *, void *, void *);
void *func_01EE34E0(s32 *out) {
    void *pool;
    Hdr *h;
    *out = 0;
    pool = func_01EE3D48(0x100);
    if (pool == 0) {
        return 0;
    }
    h = func_01EE3DB0(pool, sizeof(Hdr));
    h->f0 = out;
    h->f8 = 0x1000;
    h->f4 = 0;
    return func_01EE40B8(pool, h, func_01EE32FC, func_01EE347C, func_01EE34A8);
}
