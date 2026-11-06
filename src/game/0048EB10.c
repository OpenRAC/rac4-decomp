#include "pal/record_tables.h"
extern void *D_002214D8;

/* Read the record field at offset 0x00; use the low 16 handle bits. */
s32 func_0048EB10(s32 handle)
{
    s32 index = handle & 0xFFFF;
    if (D_002214D8 != NULL && ((PalRecordTables *)D_002214D8)->small_limit >= index)
        goto found;
    return -1;
found:
    return *(u16 *)((index << 3) + (u32)((PalRecordTables *)D_002214D8)->small_records + 0);
}
