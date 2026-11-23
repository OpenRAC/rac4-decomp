#include "common.h"

extern u32 D_002214F4;
extern u32 D_00221510;
extern s32 D_0021EE54;
extern s32 func_00477FF0(s32);

/* Validate in order, with two successful predicate arms and one failure exit. */
s32 func_00478000(void *arg0)
{
    u8 *payload;

    if (arg0 == NULL)
        return 0;
    if ((u32)arg0 >= D_002214F4 &&
        (u32)arg0 <= D_00221510) {
        if (D_0021EE54 == 1) {
            payload = *(u8 **)((u8 *)arg0 + 0x24);
            if (payload != NULL && payload[0x46] == 9)
                return 1;
        } else {
            if (func_00477FF0(*(s16 *)((u8 *)arg0 + 0xBC)) != 0)
                return 1;
        }
    }
    return 0;
}
