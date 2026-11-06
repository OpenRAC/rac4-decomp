#include "common.h"

typedef struct Object Object;
typedef struct {
    u8 prefix[0x14];
    s32 (*supports)(Object *, u32);
} Vtable;
typedef struct {
    f32 x, y;
} Pair;
struct Object {
    u32 first;
    u8 flags;
    u8 reserved[3];
    Vtable *vtable;
    u32 options;
    f32 scale;
    Pair position, size, offset;
    u32 spare, first_handle, second_handle;
};
extern s32 func_005015E0(Object *, const Object *);
s32 func_0050BFA8(Object *destination, Object *source)
{
    if (source->vtable->supports(source, 1)) {
        func_005015E0(destination, source);
        destination->options = source->options;
        destination->scale = source->scale;
        destination->position = source->position;
        destination->size = source->size;
        destination->offset = source->offset;
        destination->first_handle = source->first_handle;
        destination->second_handle = source->second_handle;
        return 1;
    }
    return 0;
}
