/* cflags: -Wuninitialized */
#include "pal/l00_menu_queue.h"

MenuQueueNode *D_00220ABC = NULL;

MenuQueueNode *func_L00_0070D768(void)
{
    MenuQueueNode *node = D_00220ABC;

    if (node != NULL) {
        D_00220ABC = node->next;
        node->next = NULL;
    }
    return node;
}
