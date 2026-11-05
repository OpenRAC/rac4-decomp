#include "common.h"

typedef struct ResourceRecord {
    void *buffer;
    u32 handle;
} ResourceRecord;

extern u8 D_001C20C0[];
extern ResourceRecord *func_0049A110(void *descriptor, s32 sectorBase);

static inline u32 add_address(u32 base, u32 offset)
{
    return base + offset;
}

u32 func_0049A9D8(void *descriptor, s32 sectorBase)
{
    ResourceRecord *record;

    if (sectorBase < 0) {
        u8 *archive = (u8 *)add_address((u32)D_001C20C0, 0x8000);
        sectorBase = *(s32 *)(archive + 0x3444);
    }
    record = func_0049A110(descriptor, sectorBase);
    if (record) {
        return record->handle;
    }
    return 0;
}
