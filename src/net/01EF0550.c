/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct {
    u8 unknown[0x10];
    void (*callback)(void);
} CallbackTable;

typedef struct {
    u8 unknown[0x10418];
    u32 counter;
    CallbackTable *table;
} Object;

void func_01EF0550(Object *object)
{
    object->table->callback();
    ++object->counter;
}
