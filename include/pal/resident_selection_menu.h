#ifndef PAL_RESIDENT_SELECTION_MENU_H
#define PAL_RESIDENT_SELECTION_MENU_H

#include "common.h"

typedef struct {
    u8 bytes[24];
} PalSelectionMenuRow;

typedef struct {
    u8 prefix[0x2C];
    s32 handle;
    u8 rest[0x3C];
} PalSelectionMenuList;

typedef struct {
    s32 phase, dirty;
    u8 prefix[0xD04];
    PalSelectionMenuRow rows[64];
    PalSelectionMenuList list;
    char text[16];
    s32 value, unused138C;
    s32 resources[4];
    u8 pad13A0[8];
    u8 mark13A8, mark13A9, flag;
} PalSelectionMenu;

typedef struct {
    s32 kind, other, count;
} PalSelectionData;

typedef struct {
    s32 a, b;
    PalSelectionData *data;
    u8 tail[12];
} PalSelectionItem;

typedef struct {
    u8 pad[0x34];
    PalSelectionItem *items;
    u8 gap[0x18];
    s32 count, index;
} PalSelectionList;

extern PalSelectionMenu D_0030D188;
extern PalSelectionList D_0030E494;

static inline PalSelectionItem *pal_selected_item(const PalSelectionList *list)
{
    if (list->index < 0) {
        return 0;
    }
    return list->items + list->index;
}

#endif
