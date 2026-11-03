#include "common.h"
typedef struct {
    s32 a, b, c;
} Entry;
extern Entry *func_00504C08(Entry *);
extern void func_00504BF0(Entry *, s32, s32, s32, s32);
Entry *func_00504C20(Entry *entries)
{
    Entry *p = entries;
    s32 count = 15;
    Entry value;
    do {
        func_00504C08(p);
        p++;
        count--;
    } while (count != -1);
    func_00504BF0(&value, 0, 0, 0, 0);
    {
        Entry *next = entries;
        do {
            *next = value;
            next++;
        } while ((s32)next < (s32)(entries + 16));
    }
    return entries;
}
