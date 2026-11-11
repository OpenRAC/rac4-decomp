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
extern Entry D_002F3950[];
extern Block *func_00499320(u32, s32);
extern s32 func_004A2D90(Object *, void *, s32);
extern void func_00499538(Entry *);
Entry *func_004993D8(Spec *spec, s32 value)
{
    Entry *empty = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_002F3950[i].spec == spec) {
            D_002F3950[i].references++;
            return &D_002F3950[i];
        }
        if (!D_002F3950[i].references && !empty)
            empty = &D_002F3950[i];
    }
    if (empty) {
        Block *b = func_00499320(spec->sectors << 11, 1);
        if (b) {
            empty->references++;
            empty->unknown = value;
            empty->spec = spec;
            func_004A2D90(empty->object, 0, 0);
            empty->block = b;
            func_00499538(empty);
        } else
            empty = 0;
    }
    return empty;
}
