#include "common.h"

typedef struct Player {
    u8 prefix[0x2F10];
    s32 slot;
} Player;
extern u8 D_003098F0[];
extern s32 D_001711D0[];
extern u8 D_00171EF0[];
extern char D_0021F838[];
extern Player *func_00510BE8(s32 context);
extern const char *func_0045E038(s32 id);
extern s32 func_0011D920(char *output, const char *format, ...);

void func_004B5BE0(s32 context)
{
    u32 state = (u32)D_003098F0 + (u32)context * 0x1F8u;
    Player *player = func_00510BE8(context);
    char *text = (char *)(state + 0xD4);
    u32 slot = (u32)player->slot * 4u;
    const char *format = D_0021F838;
    s32 item = *(s32 *)((u32)D_001711D0 + slot);
    const char *label = func_0045E038(0x3162);
    u32 record = (u32)item * 40u + slot + (u32)D_00171EF0;
    s32 percent = (s32)((u32) * (s32 *)record * 100u) / 64;

    func_0011D920(text, format, label, percent);
}
