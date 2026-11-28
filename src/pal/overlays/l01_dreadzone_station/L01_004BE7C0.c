#include "common.h"

typedef struct {
    u8 pad00[0xC];
    s32 tableIndex;
} StationObjectState;

typedef struct {
    u8 pad00[0xAC];
    StationObjectState *state;
} StationObject;

typedef struct {
    union {
        s32 word;
        s16 halfwords[2];
    } id;
    u8 pad04[0xC];
} StationTableEntry;

extern StationTableEntry D_L01_003AADF8[];
extern s32 func_0045E0A0(s32 id);

s64 func_L01_004BE7C0(StationObject *object)
{
    StationTableEntry *entry;
    s64 result;
    s32 active;

    entry = &D_L01_003AADF8[object->state->tableIndex];
    result = 0;
    if (entry->id.word != -1) {
        active = func_0045E0A0(entry->id.halfwords[0]) != 0;
        result = active;
    }
    return result;
}
