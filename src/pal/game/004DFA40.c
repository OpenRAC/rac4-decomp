#include "common.h"
typedef struct {
    u8 active;
    u8 pad[3];
    u32 color, unused, base;
    u8 tail[16];
} Row;
typedef struct {
    u8 pad[8];
    s16 count;
    u8 gap[0x12];
    Row *rows;
} Manager;
extern Manager *D_00221DF0;
extern s32 func_001633D8(void);
void func_004DFA40(void)
{
    s32 i;
    for (i = 0; i < D_00221DF0->count; i++) {
        Row *p = D_00221DF0->rows + i;
        if (p->active) {
            s32 random = func_001633D8() >> 16;
            {
                s32 red = ((random & 0x1F00) << 10) - 0x202020;
                s32 green = (random & 0x1F0) << 6;
                s32 blue = (random & 0x1F) << 2;
                p->color = p->base + red + green + blue;
            }
        }
    }
}
