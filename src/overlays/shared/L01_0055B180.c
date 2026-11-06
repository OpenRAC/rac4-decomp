#include "common.h"

typedef struct SceneObject SceneObject;
extern SceneObject *func_L01_00428860(SceneObject *parent, const void *position,
                                      const void *rotation, u8 mode, u32 first,
                                      u32 second, u32 initial, u32 count,
                                      u32 word8, u32 word9);

SceneObject *func_L01_0055B180(SceneObject *parent, const void *position, const void *rotation, u32 mode, u32 first, u32 second, u32 initial, u32 count, u32 word8, u32 word9)
{
    return func_L01_00428860(parent, position, rotation, (u8)mode, first,
                             second, initial, count, word8, word9);
}
