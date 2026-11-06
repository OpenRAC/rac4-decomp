#include "common.h"
typedef struct Block Block;
typedef struct Object Object;
typedef struct Spec {
    s32 id;
    u32 sectors;
} Spec;
typedef struct Entry {
    Block *block;
    Object *object;
    s32 references, unknown;
    Spec *spec;
} Entry;
extern Entry D_002F3A50[];
extern Block *func_0049A058(u32, s32);
extern s32 func_004A3AF0(Object *, void *, s32);
extern void func_0049A270(Entry *);
Entry *func_0049A110(Spec *spec, s32 value)
{
    Entry *empty = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_002F3A50[i].spec == spec) {
            D_002F3A50[i].references++;
            return &D_002F3A50[i];
        }
        if (!D_002F3A50[i].references && !empty)
            empty = &D_002F3A50[i];
    }
    if (empty) {
        Block *b = func_0049A058(spec->sectors << 11, 1);
        if (b) {
            empty->references++;
            empty->unknown = value;
            empty->spec = spec;
            func_004A3AF0(empty->object, 0, 0);
            empty->block = b;
            func_0049A270(empty);
        } else
            empty = 0;
    }
    return empty;
}
