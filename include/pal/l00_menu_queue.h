#ifndef RAC4_PAL_L00_MENU_QUEUE_H
#define RAC4_PAL_L00_MENU_QUEUE_H

#include "common.h"

typedef struct MenuQueueNode MenuQueueNode;
struct MenuQueueNode {
    u8 opaque[0x19C];
    MenuQueueNode *next;
};

extern MenuQueueNode *D_00220ABC;
extern MenuQueueNode *D_00220AC8;
extern MenuQueueNode *D_00220ACC;

#endif
