#include "common.h"

typedef struct Object Object;
typedef struct {
    s32 enabled;
    u16 kind;
    u16 unused;
    u32 mask;
} Event;
typedef struct {
    u32 id;
    u16 kind;
    u8 data[6];
} Action;
typedef struct {
    u32 unused;
    u16 kind;
    u16 unused06;
    u32 mask;
    Action actions[15];
} Handler;
typedef struct {
    void *unused[9];
    s32 (*fallback)(Object *, const Event *);
} VTable;
struct Object {
    u32 unused00, unused04;
    VTable *vtable;
    u32 flags;
    u8 pad10[0x2C];
    const Handler **handlers;
};
typedef struct {
    s32 unused;
    void *context;
} Manager;

extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern s32 func_0050C090(Object *, const Event *);
extern void *func_00500ED0(Manager *);
extern s32 func_00503D78(void *, const Action *);

static inline Manager *getManager(void)
{
    if (D_00222038[0].context)
        return D_00222038;
    return func_005010E0();
}

s32 func_0050C100(Object *object, const Event *event)
{
    s32 handled = 0;
    u32 index;
    s32 action, matches;
    const Handler *handler;

    if (!(object->flags & 2) && !event->enabled)
        goto done;
    handled = func_0050C090(object, event);
    if (object->handlers) {
        for (index = 0; *(const Handler **)((u32)object->handlers + (index << 2)); index++) {
            handler = *(const Handler **)((u32)object->handlers + (index << 2));
            matches = 0;
            if (event->kind == 1) {
                if (handler->kind == 1 && (event->mask & handler->mask))
                    matches = 1;
            } else if (handler->kind == event->kind) {
                matches = 1;
            }
            if (matches) {
                handled = 1;
                for (action = 0;
                     action < 15 && handler->actions[action].kind;
                     action++) {
                    func_00503D78(func_00500ED0(getManager()),
                                  &handler->actions[action]);
                }
            }
        }
    }
    if (!handled)
        object->vtable->fallback(object, event);
done:
    return handled;
}
