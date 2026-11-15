/* Not matching yet: 8/20 (40.00%) relocation-masked positional words; 76/80 candidate/target bytes. Shared context type needs reconciliation across existing callers. Reproduce: python tools/check_func.py --version pal func_L01_00434608 nonmatching/pal/l01_dreadzone_station/func_L01_00434608.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

struct CallContext;
extern struct CallContext D_00222C28;
extern void func_00453180(struct CallContext *context, void *records, s32 value);

void func_L01_00434608(void *object)
{
    u8 kind;
    void *data;

    if (object != NULL && (kind = *(u8 *)((u8 *)object + 0x20), kind != 0xFE)) {
        if (kind != 0xFD) {
            data = *(void **)((u8 *)object + 0xAC);
            if (data != NULL) {
                func_00453180(&D_00222C28, (u8 *)data + 0x40, *(s32 *)((u8 *)data + 0x10));
            }
        }
    }
}
