/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

#include "pal/l00_hash_table.h"
#include "pal/l00_record_iteration.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;

struct Type1 {
    u8 pad[0x1C];
    HashTable *f1C;
};

struct Type2 {
    Type1 *f0;
    Type3 *f4;
    HashTable *f8;
};

extern const char D_004ACE68[];
extern const char D_004ACE80[];
extern Type3 *func_L00_00521408(void);
extern void func_L00_00521468(Type3 *);
extern s32 func_L00_00521510(const char *, s32, s32, Type3 *);
extern Type3 *func_L00_00520F68(Type3 *);
extern s32 func_L00_004FAFC0(s32, s32, const char *, s32);
extern void func_L00_00507F38(void *, void *);

// Flushes expired sessions from the cache with automatic table shrinking disabled.
void func_L00_00507FF0(Type1 *arg0, s32 arg1)
{
    Type2 context;
    u64 lowerLoad;
    const char *file;

    context.f0 = arg0;
    context.f4 = func_L00_00521408();
    context.f8 = arg0->f1C;
    if (context.f8 != NULL) {
        if (arg1 == 0) {
            func_L00_00521510(D_004ACE80, 0x11, 2, context.f4);
        } else {
            func_L00_00520F68(context.f4);
        }
        file = D_004ACE68;
        func_L00_004FAFC0(9, 12, file, 0x235);
        lowerLoad = context.f8->lowerLoad;
        context.f8->lowerLoad = 0;
        func_L00_004F9140((PalL00Records *)context.f8, func_L00_00507F38, &context);
        context.f8->lowerLoad = lowerLoad;
        func_L00_004FAFC0(10, 12, file, 0x23A);
        func_L00_00521468(context.f4);
    }
}
