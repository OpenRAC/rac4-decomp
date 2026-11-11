#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern char *func_0046B930(s32 classId, s32 privateSize);
extern void func_004706F0(void *object);
extern void func_00476C38(void *object);

char *func_L01_003DAF28(const char *descriptor, const Quadword *position, u32 value, const Quadword *optional)
{
    char *object = func_0046B930(0x27F, 0x80);
    if (object != 0) {
        char *state;
        u8 mode;
        *(u8 *)(object + 0x30) = 0xFF;
        *(u8 *)(object + 0x31) = 1;
        *(u16 *)(object + 0x34) |= 1;
        *(u8 *)(object + 0x20) = 0;
        *(u8 *)(object + 0x67) = 0;
        state = *(char **)(object + 0xAC);
        *(Quadword *)(object + 0x10) = *position;
        *(Quadword *)state = optional != 0 ? *optional : *(const Quadword *)descriptor;
        *(u32 *)(state + 0x20) = value;
        *(u16 *)(object + 0x32) = *(const u8 *)(descriptor + 0x3C);
        *(u8 *)(state + 0x24) = *(const u8 *)(descriptor + 0x10);
        *(u8 *)(state + 0x25) = *(const u8 *)(descriptor + 0x11);
        *(u8 *)(state + 0x26) = *(const u8 *)(descriptor + 0x12);
        *(u8 *)(state + 0x27) = *(const u8 *)(descriptor + 0x13);
        *(u8 *)(state + 0x28) = *(const u8 *)(descriptor + 0x14);
        *(u8 *)(state + 0x29) = *(const u8 *)(descriptor + 0x15);
        *(u8 *)(state + 0x68) = *(const u8 *)(descriptor + 0x3D);
        *(u16 *)(state + 0x6C) = *(const u16 *)(descriptor + 0x40);
        *(u8 *)(state + 0x2A) = *(const u8 *)(descriptor + 0x16);
        *(u8 *)(state + 0x2B) = *(const u8 *)(descriptor + 0x17);
        *(u8 *)(state + 0x2C) = *(const u8 *)(descriptor + 0x18);
        *(u8 *)(state + 0x2D) = *(const u8 *)(descriptor + 0x19);
        *(u8 *)(state + 0x2E) = *(const u8 *)(descriptor + 0x1A);
        *(u8 *)(state + 0x69) = *(const u8 *)(descriptor + 0x3E);
        *(u16 *)(state + 0x6E) = *(const u16 *)(descriptor + 0x42);
        *(u8 *)(state + 0x2F) = *(const u8 *)(descriptor + 0x1B);
        *(u8 *)(state + 0x30) = *(const u8 *)(descriptor + 0x1C);
        *(u8 *)(state + 0x31) = *(const u8 *)(descriptor + 0x1D);
        *(u8 *)(state + 0x32) = *(const u8 *)(descriptor + 0x1E);
        *(u8 *)(state + 0x33) = *(const u8 *)(descriptor + 0x1F);
        *(u8 *)(state + 0x6A) = *(const u8 *)(descriptor + 0x3F);
        *(u16 *)(state + 0x70) = *(const u16 *)(descriptor + 0x44);
        *(f32 *)(state + 0x34) = *(const f32 *)(descriptor + 0x20);
        *(f32 *)(state + 0x38) = *(const f32 *)(descriptor + 0x24);
        *(f32 *)(state + 0x3C) = *(const f32 *)(descriptor + 0x28);
        *(f32 *)(state + 0x40) = *(const f32 *)(descriptor + 0x2C);
        *(f32 *)(state + 0x44) = *(const f32 *)(descriptor + 0x30);
        *(u8 *)(state + 0x6B) = *(const u8 *)(descriptor + 0x48);
        *(u16 *)(state + 0x72) = *(const u16 *)(descriptor + 0x46);
        *(u32 *)(state + 0x48) = *(const u32 *)(descriptor + 0x34);
        *(u32 *)(state + 0x4C) = *(const u32 *)(descriptor + 0x38);
        mode = *(const u8 *)(descriptor + 0x49);
        *(s32 *)(state + 0x64) = -1;
        *(u8 *)(state + 0x1C) = mode;
        func_004706F0(object);
        func_00476C38(object);
    }
    return object;
}
