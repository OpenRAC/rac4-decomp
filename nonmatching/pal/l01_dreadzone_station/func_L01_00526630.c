/* Not matching yet on PAL: 88B/native88B; 14 real-bound bytes
 * (12 register-field words) differ. Not part of the build. */
/* Primary L01 bindings: canonical D_00222990 is the PAL222A90 pointer cell;
 * canonical byte carrier D_00230280 + 0x50 selects pointer word PAL2303D0.
 * Actual HI/LO and full GP2259FF displacement -0x2F6F are valid. This object
 * retains the unconditional class-rejection table read and conditional ordered
 * slot/104/105/106 reads; no extra/missing primary read, helper, store, FP work
 * or allocated nontext data. Register allocation remains nonexact.
 * Primary-only evidence: mixed nominal source-linkage, complete source-ABI,
 * all-carrier and whole-link certification remain unresolved. No aggregate,
 * extent, null/range/nonalias guarantee or historical compiler flags added.
 * Retired/timeout source/CompiledSource/final artifacts remain UNKNOWN.
 * Recheck: tools/check_func.py --version pal func_L01_00526630
 * nonmatching/pal/l01_dreadzone_station/func_L01_00526630.c --diff
 * The repository comparison masks relocation fields; real bindings still
 * require independent review. No exactness or semantic acceptance is claimed.
 */
#include "common.h"

extern u8 *D_00222990;
extern u8 D_00230280[];

/* Test the ordered record status bytes for the selected class. */
s32 func_L01_00526630(s32 indexWord)
{
    u8 *context;
    u8 *table;
    u8 *record;
    s32 classValue;
    s32 result;
    u32 recordAddress;

    context = *(u8 **)(D_00230280 + 0x50);
    classValue = *(s16 *)(context + 0x86);
    table = D_00222990;
    if (classValue != 0x13) {
        return 0;
    }
    recordAddress = (u32)table + ((u32)indexWord << 5);
    record = *(u8 **)(recordAddress + 0x1C);
    result = 0;
    if (record[0x104] != 0 && record[0x105] != 0) {
        result = record[0x106] == 0;
    }
    return result;
}
