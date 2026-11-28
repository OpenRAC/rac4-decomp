/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 unknown00[8];
    s32 (*call)(s32, s32, s32, s32, s32, s32, s32);
} DispatchTable;

typedef struct {
    u8 unknown00[0x10];
    DispatchTable *table;
    u8 unknown14[0xC];
    s32 context;
} Dispatcher;

extern s32 func_00408260(s32 status);

static inline s32 dispatch(Dispatcher *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg7)
{
    return self->table->call(self->context, arg1, arg2, arg3, arg4, arg5, arg7);
}

s32 func_L00_00548958(Dispatcher *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 status = dispatch(self, arg1, arg2, arg3, arg4, arg5, arg7);

    if (status != 0)
        return func_00408260(status);
    return 0;
}

s32 func_L00_005489A0(Dispatcher *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 status = dispatch(self, arg1, arg2, arg3, arg4, arg5, arg7);

    if (status != 0)
        return func_00408260(status);
    return 0;
}
