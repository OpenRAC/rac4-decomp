#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
typedef struct Cache {
    u8 entries[0x20];
    s32 initialized;
} Cache;
extern Cache D_00266B88;
extern s32 D_001170D0[];
extern void func_004E8378(const void *packet);
extern char *func_0046C1F0(s32 classId, s32 privateBytes);
extern void func_00470970(void *object, u32 color, u64 first, u64 second, u64 third);
extern void func_00470FD0(void *object);

char *func_0046DFE8(s32 index, s32 classId, const Quadword *position)
{
    char **slot;
    char *object;
    func_004E8378(D_001170D0);
    D_00266B88.initialized = 1;
    slot = (char **)((u32)&D_00266B88 + (u32)index * 4U);
    if (*slot != 0)
        return *slot;
    {
        object = func_0046C1F0(classId, 0);
        if (object != 0) {
            *slot = object;
            func_00470970(object, 0x202020, 14, 14, 0);
            *(s16 *)(object + 0x32) = 0x40;
            *(s16 *)(object + 0x34) = 0x10;
            {
                Quadword newPosition = *position;
                *(u32 *)(object + 0x98) = 0;
                *(Quadword *)(object + 0x10) = newPosition;
            }
            func_00470FD0(object);
        }
    }
    return object;
}
