/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
extern s32 func_00408490(s32, Type1 **, const char *);
extern char D_004A2FC8[];

/* Reads an 8-byte record and checks its size. */
s32 func_L00_00533490(s32 *arg0, s32 arg1) {
    Type1 *record;
    s32 result = func_00408490(arg1, &record, D_004A2FC8);
    if (result != 0) {
        return result;
    }
    if (record->f4 != 8) {
        return 0x21E;
    }
    *arg0 = record->f0;
    return result;
}
