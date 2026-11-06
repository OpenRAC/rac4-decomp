#include "common.h"
typedef struct Object {
    u8 pad0[0x34];
    u16 flags;
    u8 pad1[0x70];
    void (*onUpdate)(struct Object *);
    u8 pad2[0x10];
    s16 kind;
} Object;
extern void func_004F6E98(Object *object);
extern void func_004F7118(Object *object);
extern s32 D_00222044;
extern void func_00470970(Object *, u32, u64, u64, u64);
/* The BC discriminator installs one of two owner callbacks.  Other kinds
* still set bit 1;
the flag store is unconditional in the retail routine. */
void func_004F6B28(Object *object)
{
    s32 clear;
    s32 changed;
    clear = 0;
    changed = 0;
    switch (object->kind) {
    case 0x1E03:
        object->flags |= 1;
        object->onUpdate = func_004F6E98;
        clear = 1;
        changed = 1;
        break;
    case 0x2766:
        object->onUpdate = func_004F7118;
        clear = 1;
        changed = 1;
        break;
    }
    if (clear != 0) {
        object->flags &= 0xFFFD;
    } else {
        object->flags |= 2;
    }
    if (changed != 0) {
        func_00470970(object, D_00222044, 0xE, 0xE, 0);
    }
}
