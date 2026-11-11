#include "common.h"

typedef struct {
    u8 *object;
    u32 color;
    s32 reserved;
    f32 fraction;
    u8 tail[16];
} Entry;
extern Entry D_00227920[];
extern u8 **func_004765B0(void *);
extern u32 func_00453C68(u32, u32, f32);
extern void func_004700B0(void *, u32, u32, u32);
void func_0042B700(s32 index, u32 color)
{
    s32 alpha;
    u8 **child;
    s32 mixed, red, green, blue;
    alpha = (s32)(D_00227920[index].fraction * 96.0f);
    D_00227920[index].object[35] = alpha;
    child = func_004765B0(D_00227920[index].object);
    if (child != 0 && *child != 0)
        (*child)[35] = alpha;
    mixed = func_00453C68(color, D_00227920[index].color, D_00227920[index].fraction);
    blue = (mixed >> 16) & 0xFF;
    green = (mixed >> 8) & 0xFF;
    red = mixed & 0xFF;
    func_004700B0(D_00227920[index].object, red, green, blue);
}
