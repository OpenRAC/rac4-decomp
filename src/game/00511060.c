#include "common.h"
typedef struct Object {
    u32 id;
    u32 unknown4;
    s32 status;
    struct Object *next;
} Object;
extern u32 D_003D37C0[];
extern Object *D_00336818[];
extern Object *D_003367E0[];
extern void *func_00510C58(u32 id);
extern void *func_0053E0D8(u32 id);
void *func_00511060(u32 id)
{
    u32 category;
    u32 slot;
    Object *object;
    if (id == 0xFFFFFFFF) {
        return NULL;
    }
    category = (id >> 24) & 15;
    slot = id & 0xFFF;
    if (category == 0) {
        return func_00510C58(id);
    }
    if (category == 2) {
        return func_0053E0D8(id);
    }
    object = (Object *)((u32)D_00336818[category] + slot * D_003D37C0[category]);
    if (object->id == id && object->status != 2) {
        return object;
    }
    object = D_003367E0[category];
    while (object) {
        if (object->id == id && object->status != 2) {
            return object;
        }
        object = object->next;
    }
    return NULL;
}
