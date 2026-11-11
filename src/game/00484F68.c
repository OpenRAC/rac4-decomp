#include "common.h"

typedef struct {
    char pad0[5];
    u8 state;
    char pad6[2];
    u32 flags;
    char padC[8];
    f32 duration;
} Animation;

typedef struct Object Object;
struct Object {
    char pad0[4];
    u32 flags;
    char pad8[4];
    s32 mismatch;
    char pad10[0x14];
    char *entries;
    char pad28[0xB];
    u8 state;
    char pad34[0x20];
    u8 index;
    u8 finalFlags;
    char pad56[6];
    Object *linked;
    char pad60[0xC];
    s32 (*callback)(Object *, s32);
};

extern s32 func_004845B8(Object *, f32);
extern void func_00481100(Object *, u8, s32);

static inline Animation *get_animation(Object *obj)
{
    char *base;
    char *entry;
    char *table;
    s32 offset;

    base = obj->entries;
    offset = obj->index * 4;
    entry = *(char **)(base + offset + 0x48);
    table = *(char **)(entry + 0x18);
    return *(Animation **)(table + 4);
}

void func_00484F68(Object *arg0, Object *arg1)
{
    Animation *animation = get_animation(arg0);
    Object *current = arg0;
    Object *linked;
    s32 (*callback)(Object *, s32);
    u8 state = arg1->state;

    if (animation->state != state) {
        if (arg1->linked != NULL) {
            animation = get_animation(arg1->linked);
            current = arg1->linked;
        }
    }
    if (animation->state == state) {
        if ((animation->flags & 2) != 0 || (arg1->flags & 0x20000) != 0) {
            if (arg1->callback != NULL) {
                arg1->callback(arg0, 1);
            }
        }
        if ((arg1->flags & 0x40000) == 0 && arg1->callback != NULL) {
            if (animation->duration > 0.0f && func_004845B8(current, animation->duration) != 0) {
                callback = arg1->callback;
                callback(arg0, 2);
                arg1->flags |= 0x40000;
            }
            if (current == arg0 && (linked = arg1->linked) != NULL) {
                Animation *linkedAnimation = get_animation(linked);
                if (linkedAnimation->state == arg1->state && linkedAnimation->duration > 0.0f &&
                    func_004845B8(linked, linkedAnimation->duration) != 0) {
                    arg1->callback(arg0, 2);
                    arg1->flags |= 0x40000;
                }
            }
        }
        if ((current->finalFlags & 2) != 0) {
            if ((animation->flags & 4) != 0) {
                if (arg1->callback != NULL) {
                    arg1->callback(arg0, 3);
                }
                arg1->flags &= ~0x40000;
            } else {
                func_00481100(arg0, arg1->state, 0);
            }
        }
    } else {
        arg1->mismatch = 1;
    }
}
