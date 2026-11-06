#include "common.h"
typedef struct {
    char pad[7];
    u8 flags, active;
    char rest[0x47];
} Entry;
typedef void (*Callback)(void *, f32);
extern Entry D_00355DC0[];
extern void *func_0011A518(void *, s32, u32);
extern void func_0048A7C8(void *, Entry **, s32, Callback, void *);
s32 func_00489FA0(void *manager, s32 wait, s32 timeout, Callback callback, void *user)
{
    Entry *list[3];
    Entry *p;
    Entry **out;
    s32 i;
    func_0011A518(list, 0, 12);
    p = D_00355DC0;
    out = list;
    for (i = 0; i < 3; i++, p++) {
        if (p->active) {
            list[i] = p;
            p->flags |= 8;
        }
    }
    if (wait)
        func_0048A7C8(manager, list, timeout, callback, user);
    return 1;
}
