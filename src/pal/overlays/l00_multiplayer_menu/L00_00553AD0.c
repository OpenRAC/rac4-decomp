/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00553B38(u8 *descriptor, u32 flags, u32 type, u32 properties);
extern void func_L00_00553B78(u8 *descriptor, const void *data, u32 length);

void func_L00_00553AD0(u8 *descriptor, u32 flags, u32 type, const void *data, u32 length, u32 properties, u32 extraFlags)
{
    func_L00_00553B38(descriptor, flags, type, properties);
    func_L00_00553B78(descriptor, data, length);
    descriptor[0x16] |= extraFlags;
}
