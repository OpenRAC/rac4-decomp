#include "common.h"

int func_L01_00597190(float x, float y, float z, void *object, int bone, int mode, int first, int second, int third);

/* Apply both bone modes from the current extension flags and byte value. */
void func_L01_0045CE10(void *arg0)
{
    void *extension;
    extension = *(void **)((s8 *)arg0 + 0xAC);
    func_L01_00597190(0.5f, (f32)*(u8 *)((s8 *)extension + 0x28C), 1.0f,
        *(void **)((s8 *)extension + 0x5F0), 5,
        (*(u16 *)((s8 *)extension + 0x32C) & 0x1000) ? 0x800 : 1, 0, 1, 0);
    func_L01_00597190(0.5f, (f32)*(u8 *)((s8 *)extension + 0x28C), 1.0f,
        *(void **)((s8 *)extension + 0x5F0), 0,
        (*(u16 *)((s8 *)extension + 0x32C) & 0x1000) ? 0x800 : 1, 0, 1, 0);
}
