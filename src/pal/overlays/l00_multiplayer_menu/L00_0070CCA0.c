#include "common.h"
#include "pal/dialog_71d890.h"
#include "pal/global_002234A4.h"
#include "pal/multiplayer_menu.h"

u8 D_L00_00220A98 = 1;

extern s32 func_L00_0076A4A8(void *data, char *name, char *detail, void *argument, s32 option);
extern const char *func_0045E850(s32 id);

/* Report a failed menu request when dialogs are enabled. */
s32 func_L00_0070CCA0(char *name, char *detail, void *argument, s32 option)
{
    struct Context *context = D_00220DD4;
    s32 result = func_L00_0076A4A8(*(void **)((u8 *)D_002234A4 + 0x34), name, detail, argument, option);
    if (!result && D_L00_00220A98) {
        const char *label = func_0045E850(0x12D3);
        func_L00_0071D890(0.6f, context, (s32)label, (s32)func_0045E850(0x12D0), 4, 0, 0, 0);
    }
    return result;
}
