#include "common.h"

typedef struct { u8 pad0[0xAC]; s32 offset; } Result;
typedef struct { s32 base; u8 data[4]; u16 length; s16 kind; s16 a; s16 b; } Record;
typedef struct { s32 count; Record rec[1]; } Table;
Result *func_L00_00665120(s16, s16);
extern void func_L00_005BCBF0(void *, void *, s32);
/* Walk a counted record list and copy each record's data to an address resolved per record. */
void func_L00_00665160(Table *arg0) {
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        Record *r = &arg0->rec[i];
        Result *result = func_L00_00665120(r->b, r->a);
        if (result != 0) {
            void *ptr;
            if (r->kind == 1) ptr = (u8 *)r->base + (u32)result;
            else ptr = (u8 *)r->base + result->offset;
            func_L00_005BCBF0(ptr, r->data, r->length);
        }
    }
}
