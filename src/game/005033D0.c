#include "common.h"

typedef struct {
    u32 field00;
    u32 field04;
    u32 field08;
} State;

typedef struct {
    State *entries[48];
} Table;

typedef struct Object Object;
typedef struct {
    void *pad[5];
    s32 (*check)(Object *, s32);
} ObjectVTable;
struct Object {
    u8 pad0[8];
    ObjectVTable *vtable;
    u8 padC[0x30];
    Table *table;
};

typedef struct {
    s32 entries[5];
    s32 index;
} Slots;

typedef struct {
    void *vtable;
    Slots *slots;
} Manager;

extern Manager D_00222038[];
extern s32 D_00220B50;
extern Object *func_005005E8(s32 arg0, s32 arg1);
extern Manager *func_005010E0(void);
extern s32 func_00502448(u8 *arg0);
extern u8 *func_00502478(u8 *arg0, u32 arg1);
extern void func_005024D0(u8 *arg0, s32 *arg1, u32 *arg2);
extern Table *func_00503A58(void);
extern State *func_00503AE8(void);
extern void func_00503B58(State *state, u32 value, u32 low, u32 high, u32 extra);

u8 *func_005033D0(u8 *p, s32 base, s32 id, s32 flags)
{
    s32 type;
    u32 count;
    s32 subtype;
    u32 subcount;
    s32 subtype2;
    u32 subcount2;
    s32 aligned;
    Table *table;
    u32 i;
    u32 j;
    u32 k;
    u32 n;
    State *entries;
    State st;
    Manager *manager;
    Slots *slots;
    s32 arg;
    Object *obj;
    Object *res;

    aligned = flags & 1;
    type = 0;
    count = 0;
    func_005024D0(p, &type, &count);
    if (type != 9)
        return p;
    p += 4;
    if (aligned)
        p = func_00502478(p, 0x1000);
    table = 0;
    if (count != 0)
        table = func_00503A58();
    for (i = 0; i < count; i++) {
        entries = func_00503AE8();
        table->entries[i] = entries;
        subtype = 0;
        subcount = 0;
        func_005024D0(p, &subtype, &subcount);
        p += 4;
        n = 0;
        for (j = 0; j < subcount; j++) {
            s32 a;
            s32 b;
            if (aligned)
                p = func_00502478(p, 0x1000);
            p += 4;
            a = func_00502448(p);
            p += 4;
            b = func_00502448(p);
            p += 4;
            func_00503B58(&st, 0, a, 0, b);
            entries[n] = st;
            if (aligned)
                p = func_00502478(p, 0x1000);
            n++;
        }
        subtype2 = 0;
        subcount2 = 0;
        func_005024D0(p, &subtype2, &subcount2);
        p += 4;
        for (k = 0; k < subcount2; k++) {
            s32 a;
            s32 b;
            s32 c;
            if (aligned)
                p = func_00502478(p, 0x1000);
            a = func_00502448(p) + base;
            p += 4;
            b = func_00502448(p);
            p += 4;
            c = func_00502448(p);
            p += 4;
            func_00503B58(&st, a, b, 0, c);
            entries[n] = st;
            if (aligned)
                p = func_00502478(p, 0x1000);
            n++;
        }
    }
    if (aligned)
        p = func_00502478(p, 0x1000);
    manager = D_00222038;
    slots = manager->slots;
    if (slots == 0)
        slots = func_005010E0()->slots;
    arg = 0;
    if (slots != 0)
        arg = slots->entries[slots->index];
    obj = func_005005E8(arg, id);
    if (obj != 0 && obj->vtable->check(obj, D_00220B50))
        res = obj;
    else
        res = 0;
    if (table != 0)
        res->table = table;
    return p;
}
