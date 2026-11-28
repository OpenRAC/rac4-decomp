/* cflags: -Wuninitialized */
#include "pal/l00_menu_queue.h"

MenuQueueNode *D_00220AC8 = NULL;
MenuQueueNode *D_00220ACC = NULL;

void func_L00_0070D7B0(MenuQueueNode *node)
{
    if (D_00220ACC != NULL)
        D_00220ACC->next = node;
    D_00220ACC = node;
    if (D_00220AC8 == NULL)
        D_00220AC8 = node;
}
