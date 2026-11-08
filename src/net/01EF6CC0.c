/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xAC];
    void *fB0;
};

void func_01EF3164(s32, void *, void *);
void func_01EF328C(s32, void *, void *);
void func_01EF339C(s32, void *, void *);
void func_01EF382C();
void func_01EF6C68(void *);
extern s32 D_00170270[];
extern s32 D_0019CC60[];
extern s32 D_0019CC68[];
extern s32 D_0019CC70[];
extern s32 D_0019CC80[];
extern s32 D_0019CC90[];

void func_01EF6CC0(Type1 *arg0) {
    func_01EF382C();
    arg0->fB0 = D_00170270;
    func_01EF6C68(arg0);
    func_01EF3164(arg0->f0, D_0019CC60, (void *)((u8 *)arg0 + 0xB4));
    func_01EF3164(arg0->f0, D_0019CC68, (void *)((u8 *)arg0 + 0xB8));
    func_01EF3164(arg0->f0, D_0019CC70, (void *)((u8 *)arg0 + 0xBC));
    func_01EF328C(arg0->f0, D_0019CC80, (void *)((u8 *)arg0 + 0x2C));
    func_01EF339C(arg0->f0, D_0019CC90, (void *)((u8 *)arg0 + 0xA0));
}
