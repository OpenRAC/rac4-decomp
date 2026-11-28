/* cflags: @ee29-01 -O2 -G8 -fno-schedule-insns -fno-schedule-insns2 */
#include "pal/l00_menu_queue.h"

MenuQueueNode *func_L00_0070D808(void)
{
    MenuQueueNode *node = D_00220AC8;

    if (node != NULL) {
        D_00220AC8 = node->next;
        if (D_00220AC8 == NULL)
            D_00220ACC = NULL;
        node->next = D_00220ABC;
        D_00220ABC = node;
    }
    return node;
}
