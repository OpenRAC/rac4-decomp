#include "common.h"

typedef struct Stream {
    s32 state : 8;
    s32 id : 4;
    s32 rest : 20;
    s32 count;
} Stream;

typedef struct Voice {
    u8 pad0[0x4];
    u8 *obj;
    u8 pad8[0x8];
    u8 active;
    u8 pad11[0x6F];
} Voice;

extern Voice D_001D2540[];
typedef struct Sound {
    u8 pad0[0x90];
    s32 banks[16];
} Sound;
extern Sound D_001D2280;
extern void func_004E2A78(Voice *);
extern void func_001585D8(s32, void *, Stream *);
extern void func_00439DD8(void);

// Astrm stream update
void func_00439BB8(Stream *s) {
    Voice *v;
    s32 i;
    s32 found;

    if (s->state == 1) {
        found = 0;
        v = D_001D2540;
        i = 0;
        do {
            if (v->active != 0 && *(s32 *)(v->obj + 0x1C) == s->id) {
                found = 1;
                if (s->count == 0 || --s->count == 0) {
                    func_004E2A78(v);
                }
                break;
            }
            i++;
            v++;
        } while (i < 0x34);
        if (found == 0) {
            func_001585D8(D_001D2280.banks[s->id], func_00439DD8, s);
            s->state = 3;
        }
    }
    if (s->state == 2) {
        func_001585D8(D_001D2280.banks[s->id], func_00439DD8, s);
        s->state = 3;
    }
}
