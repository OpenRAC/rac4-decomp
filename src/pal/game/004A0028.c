#include "common.h"

typedef struct {
    u8 f0;
    char p1[11];
} Entry;

typedef struct {
    char p0[0x24];
    u8 f24;
    char p25[7];
    s32 f2C;
    s32 f30;
    char p34[8];
    Entry *f3C;
    s32 f40;
    char p44[0x1BC];
} Record;

extern Record D_00307354[];
extern void func_004A0928(s32);
extern void func_0049E040(s32, s32, s32);
extern void func_0049D138(s32, s32, s32, s32, s32);
extern void func_004A0770(void);
extern void func_004A0490(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_0049DD20(s32, s32, f32, f32, f32, f32);
extern void func_0049DFB8(s32, s32);
extern void func_0049CFC8(s32, s32);

void func_004A0028(s32 index, s32 value)
{
    Record *p;
    s32 id;
    s32 i;
    f32 values[4];

    p = &D_00307354[index];
    if (p->f24 != 0) {
        return;
    }
    p->f24 = 1;
    p->f40 = value;
    if (p->f3C[p->f2C].f0 == 0) {
        for (i = 0; i < p->f30; i++) {
            if (p->f3C[i].f0 != 0) {
                p->f2C = i;
                break;
            }
        }
    }
    func_004A0928(index);
    id = (index << 6) + 0x140002;
    func_0049E040(index, 0, id);
    func_0049D138(index, 0, id, (index << 6) + 0x140003, 0);
    func_004A0770();
    func_004A0490(index, &values[0], &values[1], &values[2], &values[3]);
    func_0049DD20(index, 0, values[0], values[1], values[2], values[3]);
    func_0049DFB8(index, 1);
    func_0049CFC8(index, 1);
}
