#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
typedef struct Cache {
    u8 entries[0x20];
    s32 initialized;
} Cache;
extern Cache D_00266A88;
extern s32 D_001170D0[];
extern void func_004E7450(const void *packet);
extern char *func_0046B930(s32 classId, s32 privateBytes);
extern void func_00470090(void *object, u32 color, u64 first, u64 second, u64 third);
extern void func_004706F0(void *object);

char *func_0046D708(s32 index, s32 classId, const Quadword *position)
{
    char **slot;
    char *object;
    func_004E7450(D_001170D0);
    D_00266A88.initialized = 1;
    slot = (char **)((u32)&D_00266A88 + (u32)index * 4U);
    if (*slot != 0)
        return *slot;
    {
        object = func_0046B930(classId, 0);
        if (object != 0) {
            *slot = object;
            func_00470090(object, 0x202020, 14, 14, 0);
            *(s16 *)(object + 0x32) = 0x40;
            *(s16 *)(object + 0x34) = 0x10;
            {
                Quadword newPosition = *position;
                *(u32 *)(object + 0x98) = 0;
                *(Quadword *)(object + 0x10) = newPosition;
            }
            func_004706F0(object);
        }
    }
    return object;
}
