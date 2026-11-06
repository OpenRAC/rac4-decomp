/* cflags: -G16 */
#include "common.h"

typedef void (*Callback)(s32);
typedef struct {
    f32 x, y, width, height;
} Position;
typedef struct {
    u8 enabled;
    u8 unknown1[3];
    const char *text;
    Callback callback;
} MenuEntry;
typedef struct {
    u8 unknown0[0x1F4];
    s32 count;
} State;

Position D_0021F890 = {0.5f, 0.5f, 0.529296875f, 0.048076923936605453f};
Position D_0021F8A0 = {0.25f, 0.25f, 0.41015625f, 0.03846153989434242f};
extern State D_003099F0[];
extern const Position D_003D9398[];
extern u8 D_00171E75[];
extern s32 D_0021EE54;
extern s32 func_00498468(s32);
extern void func_004A0ED0(s32, const char *);
extern void func_004A0398(s32, f32, f32, f32, f32);
extern void func_004A0F10(s32, s32);
extern void func_004A0D78(s32, s32, MenuEntry *);
extern void func_004A0028(s32, Callback);

void func_004B6D60(s32 index, Callback callback, const char *title)
{
    State *state = (State *)((u32)D_003099F0 + (u32)index * 0x1F8);
    const Position *position = (const Position *)((u32)D_003D9398 + (u32)func_00498468(index) * 16);

    if (D_00171E75[0] == 4) {
        if (func_00498468(index) == 2) {
            position = &D_0021F890;
        }
        if (func_00498468(index) == 4) {
            position = &D_0021F8A0;
        }
    }
    func_004A0ED0(index, title);
    func_004A0398(index, position->x, position->y, position->width, position->height);
    func_004A0F10(index, D_0021EE54 != 1);
    func_004A0D78(index, state->count, (MenuEntry *)((u32)state + 0x194));
    func_004A0028(index, callback);
}
