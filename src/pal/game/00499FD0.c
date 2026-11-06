#include "common.h"

typedef struct PoolObject {
    s32 active;
    void *vtable;
    u32 first, second, third;
} PoolObject;
extern u8 D_002F35D0[];
s32 D_00221638 = 0;
extern void *func_004A3A70(PoolObject *object);

PoolObject *func_00499FD0(s32 index)
{
    if (D_00221638 == 0) {
        PoolObject *object = (PoolObject *)D_002F35D0;
        s32 count = 31;
        do {
            func_004A3A70(object);
            count--;
            object++;
        } while (count != -1);
        D_00221638 = 1;
    }
    return (PoolObject *)((u32)D_002F35D0 + (u32)index * 20u);
}
