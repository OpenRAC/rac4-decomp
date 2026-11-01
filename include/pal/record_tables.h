#ifndef PAL_RECORD_TABLES_H
#define PAL_RECORD_TABLES_H

#include "common.h"

/* Partial layout of the tables referenced by D_002215D8. Limits are inclusive. */
typedef struct {
    u8 pad00[0x3014];
    s32 record_limit;
    u8 *records;
    u8 pad301C[8];
    s32 small_limit;
    u8 *small_records;
} PalRecordTables;

extern void *D_002215D8;

#endif
