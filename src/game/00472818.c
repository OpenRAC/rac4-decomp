#include "common.h"
typedef struct Object Object;
typedef struct {
    s32 f0;
    s32 (*f4)(Object *);
} Entry;
struct Object {
    char pad[0x20];
    u8 type;
    char pad21[0x9B];
    s16 index;
};
typedef struct {
    s32 f0;
    u32 flags;
} Flags;
extern Entry *func_0046D428(s32, s32, s32);
extern Flags *func_004765F0(Object *);
s32 func_00472818(Object *p)
{
    Entry *e;
    Flags *f;
    if (!p || p->type == 254 || p->type == 253)
        return 1;
    e = func_0046D428(p->index, 14, 28);
    if (e && e->f4 && e->f4(p))
        return 1;
    f = func_004765F0(p);
    if (f && (f->flags & 0x100))
        return 1;
    return 0;
}
