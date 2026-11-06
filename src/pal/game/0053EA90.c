#include "common.h"
typedef struct {
    s32 count;
} Manager;
typedef struct {
    char pad[0x2EF8];
    s32 *state;
    char gap[0x1C];
    s32 owner;
} Object;
extern Manager *D_0021DE2C, *D_0021DE30;
extern Object *func_00511CC0(s32), *func_00511CE8(s32);
void func_0053EA90(s32 owner, s32 id)
{
    s32 i;
    for (i = 0; i < D_0021DE2C->count; i++) {
        Object *p = func_00511CC0(i);
        if (p && p->owner == owner && p->state) {
            if (*p->state == id)
                p->owner = 0;
        }
    }
    for (i = 0; i < D_0021DE30->count; i++) {
        Object *p = func_00511CE8(i);
        if (p && p->owner == owner && p->state) {
            if (*p->state == id)
                p->owner = 0;
        }
    }
}
