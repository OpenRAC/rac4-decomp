#include "common.h"
typedef struct { u8 pad0[0x10]; u8 col[2][4]; u8 pad[0x18]; } Ent;
typedef struct { u8 pad[0x14]; f32 a; f32 pad2; } A;
typedef struct { f32 x, y, w, h; u8 pad[0x4]; u16 id; } B;
extern Ent D_0024F120[];
void func_L01_00573688(A *a, B *b)
{
    s32 i;
    f32 prod;
    for (i = 0; i < 2; i++) {
        u8 *c = D_0024F120[b->id].col[i];
        prod = *(f32 *)((u8 *)a + 0x18) * *(f32 *)((u8 *)b + 8);
        if (*(f32 *)((u8 *)b + 0xC) > 0.0f) {
            if ((f32)c[3] < prod) {
                c[0] = (b->x + 32.0f) * 3.96f;
                c[1] = (b->y + 32.0f) * 3.96f;
                c[2] = *(f32 *)((u8 *)a + 0x14) * 31.875f;
                c[3] = prod;
                return;
            }
        }
    }
}
