#include "common.h"

typedef struct {
    s32 kind, index;
    u8 data[12];
    s32 result;
} Event;
typedef struct {
    u8 prefix[0x38];
    s32 selection;
    u8 tail[0x28];
} State;
typedef struct {
    s16 f0, f2;
} Info;
typedef struct {
    u8 prefix[8];
    s16 f8;
} Config;
extern State D_0030EAA0[];
s32 D_0021EE54 = 0;
extern s32 D_0021EE58;
extern s32 func_00506BB8(void);
extern void func_004999D0(Event *);
extern const char *func_004CDB70(void);
extern s32 func_004CDC60(s32);
extern s32 func_004CDE78(s32);
extern const Info *func_0047DB88(s32);
extern const Config *func_0054A290(s32, s32);
extern const char *func_0045E850(s32);
const char *func_004CDA88(s32 index)
{
    Event event;
    State *state = (State *)((u32)D_0030EAA0 + (u32)func_00506BB8() * 0x64);
    s32 text;
    s32 selection;
    if (index == 8) {
        event.kind = 5;
        event.index = state->selection;
        func_004999D0(&event);
        text = event.result;
        goto display;
    }
    if (index == 9)
        return func_004CDB70();
    if (D_0021EE54 != 0 || D_0021EE58 != 1) {
        if (index < 8) {
            text = func_0047DB88(func_004CDC60(index))->f2;
            goto display;
        }
        selection = func_004CDC60(index);
    } else
        selection = func_004CDE78(index);
    text = func_0054A290(selection, 0)->f8;
display:
    return func_0045E850(text);
}
