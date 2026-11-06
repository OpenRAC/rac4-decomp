#include "common.h"

typedef struct SceneObject SceneObject;
typedef struct MotionInfo MotionInfo;
typedef struct CallbackContext {
    u8 prefix[0x10];
    SceneObject *object;
    u8 unknown14[0x1C];
    f32 point[4];
} CallbackContext;
extern void func_L00_005F4188(SceneObject *object, f32 *output,
                              const MotionInfo *optional_info);

void func_L01_00511A58(void *unused, CallbackContext *context)
{
    if (context->object != NULL)
        func_L00_005F4188(context->object, context->point, NULL);
}
