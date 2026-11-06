#include "pal/record_tables.h"

/* Read the record field at offset 0x00; use the low 16 handle bits. */
s32 func_0048F4C0(s32 handle)
{
    s32 index = handle & 0xFFFF;
    if (D_002215D8 != NULL && ((PalRecordTables *)D_002215D8)->record_limit >= index)
        goto found;
    return -1;
found:
    return *(u16 *)((index << 5) + (u32)((PalRecordTables *)D_002215D8)->records + 0);
}
