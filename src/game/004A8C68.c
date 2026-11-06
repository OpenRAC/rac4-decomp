#include "common.h"

typedef struct {
    u8 pad00[0x24];
    s32 first;
    s32 second;
    u8 pad2C[0x8C];
} Entry;
extern Entry D_00308108[];
extern s32 D_0020C690[][3];

s32 *func_004A8C68(s32 index)
{
    Entry *entry = &D_00308108[index];
    if (entry->first != 0) {
        return &entry->first;
    }
    if (entry->second != 0) {
        return &entry->second;
    }
    return D_0020C690[index];
}
