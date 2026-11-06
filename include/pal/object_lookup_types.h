#ifndef PAL_OBJECT_LOOKUP_TYPES_H
#define PAL_OBJECT_LOOKUP_TYPES_H

#include "common.h"
#define PAL_LOOKUP_OFFSET(type, member) ((u32)&(((type *)0)->member))

typedef struct Object Object;
typedef struct VTable {
    u8 pad00[0xC];
    u32 (*getType)(Object *);
    s32 pad10;
    s32 (*isType)(Object *, u32);
} VTable;
struct Object {
    u8 pad00[8];
    VTable *vtable;
};
typedef struct Manager {
    s32 f0;
    void *context;
} Manager;

typedef char pal_object_vtable_offset[(PAL_LOOKUP_OFFSET(Object, vtable) == 8) ? 1 : -1];
typedef char pal_vtable_type_offset[(PAL_LOOKUP_OFFSET(VTable, getType) == 0xC) ? 1 : -1];
typedef char pal_vtable_test_offset[(PAL_LOOKUP_OFFSET(VTable, isType) == 0x14) ? 1 : -1];
typedef char pal_manager_context_offset[(PAL_LOOKUP_OFFSET(Manager, context) == 4) ? 1 : -1];
typedef char pal_manager_size[(sizeof(Manager) == 8) ? 1 : -1];

extern Manager D_00223248[];
extern void *func_00502150(void);
extern void *func_00501658(void *, u32);

#endif
