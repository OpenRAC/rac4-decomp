#include "common.h"
typedef struct {
    s32 a, b, c;
} Entry;
typedef struct {
    s32 pad;
    char *table;
} Manager;
extern char *D_0021DE54;
extern void func_00504BF0(Entry *, s32, s32, s32, s32);
extern void *func_00501648(void *);
extern s32 func_00504E10(void *, const Entry *);
extern void func_00500F50(void *);
void func_00501F70(Manager *manager)
{
    char *state = manager->table;
    void *p = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    if (p) {
        s32 value = *(s32 *)(D_0021DE54 + 0x1C4);
        if (value) {
            Entry entry;
            func_00504BF0(&entry, 0, 1, 0x10000, value);
            func_00504E10(func_00501648(p), &entry);
        }
        func_00500F50(p);
    }
}
