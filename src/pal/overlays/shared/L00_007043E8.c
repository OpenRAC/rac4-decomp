/* cflags: @ee29 -O2 -G0 */
#include "common.h"
#include "pal/callback_queue.h"

struct PalCallbackQueueEntry {
    u8 pad00[2];
    u8 f02;
    u8 pad03[0x1D];
    PalCallbackQueueEntry *next;
};

struct PalCallbackQueue {
    u8 pad00[0x20];
    u8 count;
    u8 pad21[0xB];
    PalCallbackQueueEntry *head;
};

PalCallbackQueueEntry *func_L00_007043E8(PalCallbackQueue *queue)
{
    PalCallbackQueueEntry *next;

    if (queue->head == NULL)
        return NULL;

    queue->head->f02 = 0xFF;
    next = queue->head->next;
    queue->count--;
    queue->head = next;
    return next;
}
