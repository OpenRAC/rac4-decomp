/* cflags: -O2 -G8 */
#include "common.h"

extern u8 D_0021DF99;

// Prepends the queued entries to the object's list, then clears the queue count.
void func_L00_00771970(void *object, void *queue)
{
    s32 offset;
    s32 entry;
    s32 count;
    s32 index;
    s32 zero;

    if (object != NULL && D_0021DF99 != 0) {
        count = *(s32 *)((u8 *)queue + 4);
        index = 0;
        zero = 0;
        if (count > zero) {
            do {
                offset = index * 4;
                index += 1;
                entry = *(s32 *)((u8 *)(offset + *(s32 *)((u8 *)queue + 8)) + zero);
                *(s32 *)((u8 *)(entry + *(s32 *)((u8 *)object + 0x0C)) + zero) =
                    *(s32 *)((u8 *)object + 0x1C);
                *(s32 *)((u8 *)object + 0x1C) = entry;
                *(s32 *)((u8 *)object + 0x18) =
                    (s32)(*(s32 *)((u8 *)object + 0x18) + 1);
            } while (index < count);
        }
    }
    *(s32 *)((u8 *)queue + 4) = 0;
}
