#include "common.h"
typedef struct {
    s32 a, b, c;
} Entry;
typedef struct {
    s32 pad;
    char *table;
} Manager;
extern char *D_0021DDCC;
extern void func_00503B58(Entry *, s32, s32, s32, s32);
extern void *func_005005D8(void *);
extern s32 func_00503D78(void *, const Entry *);
extern void func_004FFEE0(void *);
void func_00500F00(Manager *manager)
{
    char *state = manager->table;
    void *p = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    if (p) {
        s32 value = *(s32 *)(D_0021DDCC + 0x1C4);
        if (value) {
            Entry entry;
            func_00503B58(&entry, 0, 1, 0x10000, value);
            func_00503D78(func_005005D8(p), &entry);
        }
        func_004FFEE0(p);
    }
}
