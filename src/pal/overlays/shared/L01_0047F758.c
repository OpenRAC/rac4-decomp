/* cflags: -O2 -G8 */
#include "common.h"

void func_L01_00598028(void *, f32, f32, f32);

// Sets the object's +0x20 byte when clear, then publishes its three float values.
void func_L01_0047F758(void *object)
{
    if (*(u8 *)((u8 *)object + 0x20) == 0) {
        *(u8 *)((u8 *)object + 0x20) = 1;
    }
    func_L01_00598028(object, 32.0f, -1.0f, 0.0f);
}
