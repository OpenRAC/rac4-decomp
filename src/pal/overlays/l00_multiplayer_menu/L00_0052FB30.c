/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"
#include "pal/parser_context.h"

typedef struct Type1 Type1;

struct Type1 {
    void *f0;
    u16 f4;
    u16 f6;
    void *f8;
    u8 fC[4];
    s64 f10;
    void *f18;
    void (*f1C)(Type1 *);
};

extern void *func_L00_004FB1D8(s32);
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);
extern void *func_L00_0051CD58(s32);
extern void *func_L00_00536790(s32);

/* Allocate the record and set its initial fields. */
Type1 *func_L00_0052FB30(void)
{
    PalParserContext context;
    Type1 *record = func_L00_004FB1D8(sizeof(*record));

    if (record == NULL) {
        context.line = 0x56;
        func_L00_004F89C8(0xD, 0xD0, 0x21, NULL, 0);
        return NULL;
    }
    record->f0 = func_L00_0051CD58(0);
    record->f8 = func_L00_00536790(4);
    if (record->f8 == NULL)
        return NULL;
    record->f4 = 0;
    record->f6 = 0;
    record->f10 = 0;
    record->f18 = NULL;
    record->f1C = NULL;
    return record;
}
