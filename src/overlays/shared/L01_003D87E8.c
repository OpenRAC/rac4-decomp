/* cflags: -fno-schedule-insns */
#include "common.h"
typedef struct { char pad[0x23]; unsigned char value; } Target;
typedef struct { char pad[0x22f0]; Target *first; Target *second; } Record;
typedef struct { char pad[0x2ef0]; Target *target; } Owner;
/* Adjust and propagate the target byte across six records. */
void func_L01_003D87E8(Owner *owner, int amount) {
    Target *target;
    Record *record;
    Record *end;
    Target *second;
    if (amount == 0) amount = -owner->target->value;
    target = owner->target;
    record = (Record *)owner;
    end = (Record *)((char *)record + 0x1e0);
    target->value += amount;
    do {
        if (record->first) record->first->value = owner->target->value;
        second = record->second;
        record = (Record *)((char *)record + 0x50);
        if (second) second->value = owner->target->value;
    } while ((int)record < (int)end);
}
