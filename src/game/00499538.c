#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC[8];
} Type1;

extern void func_00499790(void);
extern Type1 D_2F3BD0;

/* Queue arg0 on the ring at D_2F3BD0 unless it is already queued, then advance the tail. */
void func_00499538(s32 arg0) {
    s32 i;

    for (i = D_2F3BD0.f0; i != D_2F3BD0.f4; i++, i %= 8) {
        if (D_2F3BD0.fC[i] == arg0) {
            return;
        }
    }
    D_2F3BD0.fC[D_2F3BD0.f4] = arg0;
    D_2F3BD0.f8++;
    D_2F3BD0.f4 = (D_2F3BD0.f4 + 1) % 8;
    func_00499790();
}
