/* Not matching yet: BYTES 13/468 (tools/try_func.py func_0050CAC0 --diff). Not part of the build. */
#include "common.h"
typedef struct Object Object;
typedef struct Vtable {
    void *unused[3];
    u32 (*type)(Object *);
    void *f10;
    s32 (*supports)(Object *, u32);
} Vtable;
struct Object {
    s32 f0, f4;
    Vtable *vtable;
};
typedef struct {
    s32 f0;
    void *context;
} Manager;
typedef struct {
    u8 pad0[0x40];
    Object *slots[104];
    s32 f1E0, f1E4;
    s32 count;
} Type1;
extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, s32);
extern void func_005015B8(Object *);
extern s32 func_005015C8(Object *);
extern u32 D_00220B50;
static inline Object *resolve(s32 handle)
{
    Manager *m;
    Object *obj;
    void *world;
    if (D_00222038[0].context)
        m = D_00222038;
    else
        m = func_005010E0();
    world = 0;
    if (m->context)
        world = *(void **)((u32)m->context + ((u32) * (s32 *)((char *)m->context + 0x14) << 2));
    obj = func_005005E8(world, handle);
    if (obj && obj->vtable->supports(obj, D_00220B50))
        return obj;
    return 0;
}
s32 func_0050CAC0(Type1 *arg0, s32 handle, s32 index)
{
    s32 result = 0;
    Object *obj;
    s32 found;
    s32 i;
    s32 j;
    Object *prev;
    Object **p;

    if (arg0->count < 104) {
        obj = resolve(handle);
        if (obj) {
            found = 0;
            for (j = 0; j < arg0->count; j++) {
                if (arg0->slots[j] == obj)
                    found++;
            }
            if (!found && arg0->count >= index && index < 104) {
                i = arg0->count - 1;
                if (index == arg0->count) {
                    p = &arg0->slots[index];
                } else {
                    for (; i >= index; i--) {
                        Object **q = &arg0->slots[i];
                        prev = q[0];
                        if (q[1])
                            func_005015C8(q[1]);
                        q[1] = prev;
                        if (prev)
                            func_005015B8(prev);
                    }
                    p = &arg0->slots[index];
                }
                if (*p)
                    func_005015C8(*p);
                *p = obj;
                if (obj)
                    func_005015B8(obj);
                result = 1;
                arg0->count++;
            }
        }
    }
    return result;
}
