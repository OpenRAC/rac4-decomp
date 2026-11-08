/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"

struct CallContext;
struct CallParameters;

extern struct CallContext D_00222C28;
extern struct CallParameters D_003A96F0;

extern void func_004520F8(void *context, void *records, s32 count,
                        void *parameters, f32 scale);

void func_L01_004676F8(void *object)
{
    u8 *data = *(u8 **)((u8 *)object + 0xAC);

    func_004520F8(&D_00222C28, data + 0x60, 2, &D_003A96F0, 1.0f);
}
