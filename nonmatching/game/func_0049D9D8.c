/* Not matching yet: BYTES 2/316 (tools/try_func.py func_0049D9D8 --diff). Not part of the build. */
typedef struct {
    u8 pad0[0x24];
    u8 f24;
    u8 pad25[3];
    f32 f28;
    u8 pad2C[4];
} Type1;

typedef struct {
    Type1 e[10];
    u8 pad[0x20];
} Type2;

extern Type1 D_003070A8[];
extern Type2 D_003072A8[];

extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern s32 func_0049B650(s32 arg0);
extern s32 func_00505B20(void);
void func_0049DB18(s32 player, s32 index);

// Ease each slot's level toward its target and refresh the slots that changed.

void func_0049D9D8(void) {
    s32 player;
    s32 i;
    Type1 *e;
    Type1 *row;
    Type1 *alt;
    s32 r;
    s32 changed;

    player = func_00505B20();
    alt = D_003070A8;
    row = D_003072A8[player].e;
    for (i = 0; i < 1; i++) {
        if (player == 4) {
            e = &alt[i];
        } else {
            e = &row[i];
        }
        if (e->f28 == 0.0f && e->f24 == 0) {
            continue;
        }
        r = func_0049B650((s32)e);
        changed = func_004757E0(&e->f28, (f32)e->f24, 0.0f, 0.04f) != 0.0f;
        if (changed | r) {
            func_0049DB18(player, i);
        }
    }
}
