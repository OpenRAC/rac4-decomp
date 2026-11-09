#include "common.h"

typedef struct {
    u16 first, count, offset;
    u8 rest[6];
} Grid;
typedef struct {
    u16 first;
    s16 count;
} Cell;
typedef struct {
    u16 first, second, cost, flags;
} Entry;
typedef struct {
    u8 p0[0x3008];
    Cell *cells;
    u8 p300C[4];
    Grid *grids;
    u8 p3014[4];
    u8 *objects;
    u8 p301C[0x2C];
    Entry *entries;
} Manager;
extern Manager *D_002214D8;
void func_0048D228(s32 first, s32 second, s32 mask, u16 *out_first, u16 *out_second, s32 *cost)
{
    Manager *manager;
    Grid *grid;
    typedef struct {
        u8 p0[8];
        u16 grid;
        u8 pA[22];
    } Object;
    Object *object;
    Cell *cell;
    Entry *entry;
    u32 end;
    u32 index;
    *out_first = 0xFFFF;
    *out_second = 0xFFFF;
    *cost = 0xFFFFFF;
    first &= 0xFFFF;
    manager = D_002214D8;
    second &= 0xFFFF;
    object = (Object *)((u32)manager->objects + (u32)first * 32);
    grid = (Grid *)((u32)object->grid * 12 + (u32)manager->grids);
    index = grid->offset + (first - grid->first) * grid->count + (second - grid->first);
    cell = (Cell *)((u32)manager->cells + index * 4);
    entry = (Entry *)((u32)manager->entries + (u32)cell->first * 8);
    end = (u32)entry + (u32)cell->count * 8;
    while ((u32)entry < end) {
        if ((s32)entry->cost < *cost && entry->first != 0xFFFF && (entry->flags & mask) == entry->flags) {
            *out_first = entry->first;
            *out_second = entry->second;
            *cost = entry->cost;
        }
        entry = (Entry *)((u32)entry + 8);
    }
}
