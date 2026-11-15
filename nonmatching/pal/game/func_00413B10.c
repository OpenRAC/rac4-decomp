/* Not matching yet: 2/15 (13.33%) relocation-masked positional words; 56/60 candidate/target bytes. Recorded extent includes bytes from a separately declared function; callback prototype is hypothetical. Reproduce: python tools/check_func.py --version pal func_00413B10 nonmatching/pal/game/func_00413B10.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef struct {
    s32 (*callback)(s32);
    s32 argument;
} CallbackRecord;

/* Invoke a callback when a record is present and normalize its result. */
s32 func_00413B10(CallbackRecord *record)
{
    s32 result = 0;
    if (record != NULL) {
        result = record->callback(record->argument) != 0;
    }
    return result;
}
