#include "common.h"

typedef struct {
    u8 pad0[0x54C];
    u8 group;
    u8 pad54D[0xB];
    u8 item;
} SettingsSelection;

typedef struct {
    u8 pad0[0x2F00];
    SettingsSelection *settings;
} HeroSettings;

extern u8 D_0021EE98;
extern s32 D_0021DE54;
extern u8 D_00171DB8[];
extern s32 func_00506BB8(void);
extern void *func_00511CC0(s32);
extern void func_004985F0(s32);

static inline SettingsSelection *settings_selection(s32 context)
{
    if (D_0021EE98 != 0) {
        return (SettingsSelection *)D_0021DE54;
    }
    return ((HeroSettings *)func_00511CC0(context))->settings;
}

extern s32 D_003099F0[];
extern char D_0021F8C0[];
extern const char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);

void func_004B6B90(s32 arg0)
{
    SettingsSelection *selection;
    const char *format;
    s32 index;
    const char *first;
    const char *second;
    s32 item;
    s32 table;

    item = arg0 * 0x1F8 + (s32)D_003099F0;
    selection = settings_selection(arg0);
    index = selection->group * 4 + selection->item;
    item += 0x114;
    format = D_0021F8C0;
    first = func_0045E850(0x3209);
    table = (s32)D_00171DB8 - (0 - index);
    second = func_0045E850(*(u8 *)(table + 0xB4) != 0 ? 0x175 : 0x176);
    func_0011D920((char *)item, format, first, second);
}

/* Toggle the selected setting and refresh its menu label. */
void func_004B8858(void)
{
    s32 context = func_00506BB8();
    SettingsSelection *selection;
    u8 *base;
    s32 group;
    s32 item;
    u8 *setting;

    selection = settings_selection(context);

    group = selection->group;
    base = D_00171DB8;
    item = selection->item;
    base += 0xB4;
    setting = base + (group * 4 + item);
    if (*setting != 0)
        *setting = 0;
    else
        *setting = 1;
    func_004985F0(16);
    func_004B6B90(context);
}
