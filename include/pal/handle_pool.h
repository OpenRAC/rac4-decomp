#ifndef PAL_HANDLE_POOL_H
#define PAL_HANDLE_POOL_H

#include "common.h"

typedef struct HandleEntry HandleEntry;

typedef struct {
    u8 pad0[8];
    void (*activate)(HandleEntry *);
    void (*initialize)(HandleEntry *);
} HandleMethods;

struct HandleEntry {
    u32 handle;
    HandleEntry *next;
    HandleEntry *previous;
    HandleMethods *methods;
};

extern u32 D_00220C28;
extern s32 D_00220C20;
typedef struct {
    HandleEntry *live[7];
    HandleEntry *free[7];
} HandleLists;

extern HandleLists D_00339238;
HandleEntry *func_00512470(u32 handle);

#endif
