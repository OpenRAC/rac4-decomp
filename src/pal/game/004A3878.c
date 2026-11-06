#include "common.h"

typedef struct {
    s32 offset, size;
} Entry;
typedef struct {
    s32 state;
    u8 p4[8];
    void *buffer;
    u8 p10[4];
    Entry *table;
    s32 base, selected;
} Transfer;
extern s32 func_001639D0(void);
extern void func_00163550(s32);
typedef void (*Completion)(s32, s32);
extern s32 func_001638E8(s32, void *, s32, s32, const void *, Completion, s32);
s32 func_004A3878(Transfer *transfer, s32 selected)
{
    s32 result = 0;
    if (transfer->table && transfer->buffer && (transfer->state ^ 4) != 0 && (transfer->state ^ 8) != 0) {
        if (func_001639D0() == 0) {
            s32 size = *(s32 *)((u32)selected * 8 + (u32)transfer->table + 4);
            if (size > 0) {
                Entry *entry;
                transfer->selected = selected;
                result = 1;
                func_00163550(1);
                entry = (Entry *)((u32)transfer->selected * 8 + (u32)transfer->table);
                func_001638E8(0, transfer->buffer, entry->offset + transfer->base, entry->size, 0, 0, 0);
                transfer->state = 4;
            }
        } else {
            transfer->selected = selected;
            transfer->state = 16;
            result = 1;
        }
    }
    return result;
}
