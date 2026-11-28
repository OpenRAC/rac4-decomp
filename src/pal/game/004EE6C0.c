#include "common.h"
#include "pal/menu_selection_00327A60.h"
#include "pal/mode_definition_0054B050.h"

typedef struct {
    f32 vertices[8];
    PalModeDefinition definition;
} MenuIcon;

extern s32 D_00221370;

extern void func_0044B8F8(f32 *, f32, f32, f32, f32);
extern void func_0044BD28(const f32 *, u32, u64);
extern void func_0044D960(void *, s32, s32, s32);
extern s32 func_0045F378(s32, s32);
extern s64 func_0045F440(s32);
extern s32 func_0054B7D0(s32 item, s32 slot);

void func_004EE6C0(void)
{
    MenuIcon icon;
    s64 texture;

    icon.definition = *func_0054B050(func_0054B7D0(D_00327A60[0].item, D_00327A60[0].slot + 1));
    func_0044B8F8(icon.vertices, 390.0f, 345.0f, 430.0f, 385.0f);
    texture = func_0045F440(func_0045F378(icon.definition.texture, 0));
    func_0044D960(&D_00221370, 2, 1, 1);
    func_0044BD28(icon.vertices, 0xAAAAAAAA, texture);
}
